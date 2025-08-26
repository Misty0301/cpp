#include <iostream>
#include <memory>
#include <vector>

namespace resource { 

struct Data{
  std::vector<int> data;
  void ToString(){
    for(auto &it:data){
      std::cout << it << " ";
    }
  }
};

class Resource {
 public:
  Resource() = default;
  Resource(int id) { id_ = id; }
  ~Resource() = default;
  // Copy constructor will be implicitly deleted because a move constructor is
  // decleared. 显式声明移动构造函数会隐式删除拷贝构造
  // Resource(Resource&&) = default;
  Resource(Resource &&other) {
    id_ = other.id_;
    other.id_ = -1;
    // std::move exactly equivalent to a static_cast to an rvalue reference type.
    // std::move等价于一个对右值引用的static_cast
    data_ = std::move(other.data_);
    // data_ = static_cast<Data&&>(other.data_);
  }

  // Resource(const Resource&) = delete;
  // Resource& operator=(const Resource&) = delete;
  void Use();
  void Push_Data(int data){
    data_.data.push_back(data);
  }
 private:
  int id_;
  Data data_;
};

// class ResourcePtr {
//  public:
//   ResourcePtr(Resource* ptr) : ptr_(ptr) {}
//   ~ResourcePtr() = default;
//   // ResourcePtr(const ResourcePtr&&) = default;

//  private:
//   std::unique_ptr<Resource> ptr_;
// };

// class ResourceManager {
//  public:
//   ResourceManager() = default;
//   ~ResourceManager() = default;
//   void Push(Resource&& resource) { resources_.push_back(std::move(resource));
//   } void Emplace();
//  private:
//   std::vector<std::unique_ptr<Resource>> resources_;
// };

} // namespace resource