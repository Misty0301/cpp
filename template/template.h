#include <iostream>
#include <vector>

template <class T>
class Stack {
 public:
  Stack(){};
  ~Stack(){};
  void push(T item);
  T pop();
  bool empty();
  T top();
  int size();

 private:
  std::vector<T> stack_;
};

template <typename... Args>
void print(Args... args) {
  std::cout << "(";
  ((std::cout << args << ", "), ...);
  std::cout << ")\n";
}
