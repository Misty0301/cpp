#include <iostream>
#include <list>
#include <unordered_map>

template <typename K, typename V>
class LRUCache {
 public:
  explicit LRUCache(int capacity) : capacity_(capacity) {}

  V get(const K& key) {
    auto it = cache_map_.find(key);
    if (it == cache_map_.end()) {
      return V{};
    }
    cache_.splice(cache_.begin(), cache_, it->second);
    return it->second->second;
  }

  void put(const K& key, const V& value) {
    auto it = cache_map_.find(key);
    if (it != cache_map_.end()) {
      cache_.splice(cache_.begin(), cache_, it->second);
      it->second->second = value;
      return;
    }
    // 缓存已满时删除最久未使用的元素
    if (static_cast<int>(cache_.size()) == capacity_) {
      const auto& last = cache_.back();
      cache_map_.erase(last.first);
      cache_.pop_back();
    }
    cache_.emplace_front(key, value);
    cache_map_[key] = cache_.begin();
  }

 private:
  int capacity_;
  std::list<std::pair<K, V>> cache_;
  std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator>
      cache_map_;  // typename用于告诉编译器iterator是个类型

}

// list1.splice(pos, list2); // ① 整个 list2 移到 list1 的 pos 之前
// list1.splice(pos, list2, it); // ② list2 中的 it 元素移到 list1 的 pos 之前
// list1.splice(pos, list2, first, last); // ③ [first, last) 范围内的元素移动
