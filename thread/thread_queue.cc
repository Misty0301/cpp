#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <optional>

template<typename T>
class ThreadSafeQueue {
    public:
        explicit ThreadSafeQueue() = default;
  
        ThreadSafeQueue(const ThreadSafeQueue&) = delete;
        ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;
        
        void push(T item){
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(item);
            condition_variable_.notify_one();
        }

        template<typename... Args>
        void emplace(Args&&... args){
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.emplace(std::forward<Args>(args)...);
            condition_variable_.notify_one();
        }

        std::optional<T> pop(){
            std::unique_lock<std::mutex> lock(mutex_);
            condition_variable_.wait(lock,[this](){
                return !queue_.empty()||stop_;
            });
            if (stop_ && queue_.empty()){
                return std::nullopt;
            }

            T item = queue_.front();
            queue_.pop();
            return item;
        }

        void stop() noexcept{
            std::lock_guard<std::mutex> lock(mutex_);
            stop_ = true;
            condition_variable_.notify_all();
        }

        bool empty() const noexcept{
            std::lock_guard<std::mutex> lock(mutex_);
            return queue_.empty();
        }

        size_t size() const noexcept{
            std::lock_guard<std::mutex> lock(mutex_);
            return queue_.size();
        }
        
        ~ThreadSafeQueue() noexcept {
            stop();
        }
    private:
        std::queue<T> queue_;
        std::mutex mutex_;
        std::condition_variable condition_variable_;
        bool stop_ = false;
};
