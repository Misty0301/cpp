#include <iostream>
#include <algorithm>
#include <utility>
#include "resource.h"

// using namespace resource;

class MyClass{
    public:
        MyClass()=default;
        // MyClass(MyClass&& other) noexcept {
            
        // }
    private:
        resource::Data data_;
};