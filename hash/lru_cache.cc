#include <iostream>
#include <list>
#include <unordered_map>

template<typename K, typename V>
class LRUCache {
    public:
        explicit LRUCache(int capacity):capacity_(capacity) {}

    private:
        int capacity_;
        std::list<std::pair<K, V>> cache_;
        std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> cache_map_; //typename用于告诉编译器iterator是个类型
        
}