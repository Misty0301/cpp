#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

class TokenBucket {
    public:
        TokenBucket(int capacity, int refill_rate){
            capacity_ = capacity;
            tokens_ = capacity;
            refill_rate_ = refill_rate;
            last_refill_time_ = std::chrono::steady_clock::now();
        };

        bool consume(int tokens){
            RefillTokens();
            std::lock_guard<std::mutex> lock(mutex_);
            if(tokens_ >= tokens){
                tokens_ -= tokens;
                std::cout << "Consumed tokens: " << tokens << std::endl;
                return true;
            }else{
                std::cout << "Not enough tokens to consume: " << tokens << std::endl;
                return false;
            }  
        }
    private:
        void RefillTokens(){
            std::lock_guard<std::mutex> lock(mutex_);
            auto now = std::chrono::steady_clock::now();
            auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(now - last_refill_time_).count();
            if(elapsed_time > 0){
                tokens_ = std::min(capacity_, tokens_ + int(elapsed_time * refill_rate_));
                last_refill_time_ = now;

                std::cout << "Refilled tokens: " << elapsed_time * refill_rate_ << ", ";
                std::cout << "Current tokens: " << tokens_ << std::endl;
            }
        };
        int capacity_;
        int tokens_;
        int refill_rate_;
        std::chrono::steady_clock::time_point last_refill_time_;
        std::mutex mutex_;
};

void task(int id, TokenBucket& token_bucket){
    for(int i = 0; i < 100; i++){
        if(token_bucket.consume(i)){
            std::cout << "Thread " << id << " consumed token " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }else{
            std::cout << "Thread " << id << " not enough tokens to consume token " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}
int main(){
    TokenBucket token_bucket(1000, 10);
    // for(int i = 0; i < 1000; i++){
    //     if(token_bucket.consume(i)){
    //         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //     }else{
    //         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //     }
    // }
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; i++){
        threads.push_back(std::thread(task, i+1, std::ref(token_bucket)));
    }
    for(auto& thread : threads){
        thread.join();
    }
    return 0;
}