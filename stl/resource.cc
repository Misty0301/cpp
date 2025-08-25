#include "resource.h"

void Resource::Use() {
  std::cout << "Using resource:" << id_ << ", data:";
  data_.ToString();
  std::cout << std::endl;
}