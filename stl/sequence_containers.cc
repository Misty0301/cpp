#include <iostream> 
#include <vector> //动态数组
#include <list> //双向链表
#include <forward_list> //单向链表
#include <deque> //双端队列
#include <array> //静态数组

void TestVector(){
    std::cout << "TestVector:" << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    std::cout <<"size:" << v.size() 
              << "front:" << v.front() 
              << "back:" <<v.back() 
              << std::endl;
    v.pop_back();
    v.push_back(3);
    v.insert(v.begin(), 4);
    std::cout << "size:" << v.size() << "front:" << v.front() << "back:" << v.back() << std::endl;
    v.erase(v.begin());
    std::cout << "size:" << v.size() << "front:" << v.front() << "back:" << v.back() << std::endl;
    v.clear();
    std::cout << "size:" << v.size() << std::endl;
    v.reserve(10);
    // size:当前容器中实际有的元素数量 
    // capacity:当前已分配内存空间能容纳的元素数量
    std::cout <<"size:" << v.size() << " capacity:" << v.capacity() << std::endl;
    v.resize(10);
    std::cout <<"size:" << v.size() << " capacity:" << v.capacity() << std::endl;
    // 循环打印容器
    for (auto i:v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void TestDeque() {
    std::cout << "TestDeque:" << std::endl;
    std::deque<int> d;
    d.push_back(1);
    d.emplace_back(2);
    d.push_front(0);
    d.emplace_front(3);
    std::cout << "size:" << d.size() << "front:" << d.front() << "back:" << d.back() << std::endl;
    // 循环打印队列
    std::deque<int>d_copy = d;
    while(!d_copy.empty()){
        std::cout << d_copy.front() << " ";
        d_copy.pop_front();
    }
    std::cout << std::endl;
}


int main(){
    TestVector();
    std::cout << std::endl;
    TestDeque();
    return 0;
}