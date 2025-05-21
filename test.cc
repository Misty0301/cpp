#include "template/template.cc"
#include "thread/thread_queue.cc"
#include <thread>


void producer_thread(ThreadSafeQueue<int>& queue){
    for(int i=0; i<10; i++){
        queue.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    queue.stop();
}



int main() {
    Stack<int> int_stack;
    int_stack.push(1);
    int_stack.push(2);
    Stack<double> double_stack;
    double_stack.push(3.14);
    double_stack.push(2.71);
    Stack<char> char_stack;
    char_stack.push('a');
    char_stack.push('b');
    char_stack.push('c');
    char_stack.push('d');
    Stack<std::string> string_stack;
    string_stack.push("hello");
    string_stack.push("world");
    print(1,2,3,4);
    print(int_stack.size(), double_stack.size(), char_stack.size(), string_stack.size());
    return 0;
}