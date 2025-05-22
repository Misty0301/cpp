#include <iostream>
#include <mutex>
#include <thread>

namespace thread_simp {

void PrintMsg(int count) {
  for (int i = 0; i < count; i++) {
    std::cout << "Hello, world!" << std::endl;
  }
}

void PrintMsg2(int count) {
  for (int i = 0; i < count; i++) {
    std::cout << "Hello, world2!" << std::endl;
  }
}

class ThreadTest {
 public:
  void Print(int count) {
    for (int i = 0; i < count; i++) {
      std::cout << "Hello, world3!" << std::endl;
    }
  }
};

}  // namespace thread_simp

using namespace thread_simp;

int main() {
  std::mutex mtx;
  std::thread th1(PrintMsg, 10);
  std::thread th2(PrintMsg2, 10);
  ThreadTest thread_test;
  std::thread th3(&ThreadTest::Print, &thread_test, 10);
  mtx.lock();
  th1.join();
  mtx.unlock();
  th2.join();
  th3.join();

  return 0;
}