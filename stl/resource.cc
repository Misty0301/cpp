#include "resource.h"

namespace resource{
void Resource::Use() {
  if(id_ == -1){
    std::cout << "Invaild id or Resource has been released." << std::endl;
    return;
  }
  if(data_.data.empty()){
    std::cout << "Resource data is empty." << std::endl;
    return;
  }
  std::cout << "Using resource:" << id_ << ", data:";
  data_.ToString();
  std::cout << std::endl;
  return;
}
} // namespace resource