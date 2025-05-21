#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
    private:
        int capacity_;
        std::list<std::pair<int,int>> cache_;
        std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache_map_;
    public:
        explicit LRUCache(int capacity): capacity_(capacity) {}

        int get(int key){
            if(cache_map_.find(key)==cache_map_.end()){
                return -1;
            }
            cache_.splice(cache_.begin(),cache_,cache_map_[key]);
        }
        
        void put(int key, int value){
            auto it = cache_map_.find(key);
            if(it!=cache_map_.end()){
                cache_.splice(cache_.begin(),cache_,it->second);
            }
        }
}