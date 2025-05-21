LRU（Least Recently Used）Cache 是一种**缓存淘汰策略**，其核心思想是：**最近最少使用的元素最先被淘汰**。

---

### 🧠 **基本概念**

当缓存空间满了，LRU 策略会**移除最近最少被使用的数据**，以便为新数据腾出空间。

---

### 📦 LRU Cache 的典型功能

一般包含两个操作：

1. `get(key)`

   * 获取缓存中键为 `key` 的值。
   * 如果存在，返回对应的值，并将该项标记为**最近使用**。
   * 如果不存在，返回 `-1` 或 `None`。
2. `put(key, value)`

   * 将键值对 `key-value` 放入缓存中。
   * 如果已存在，则更新值，并将该项标记为**最近使用**。
   * 如果不存在，则插入新项。如果缓存已满，需要**删除最久未使用的项**。

---

### ⚙️ 实现方式

一个高效的实现通常使用：

* **双向链表（Doubly Linked List）**：记录元素的使用顺序，头部为最新使用，尾部为最久未使用。
* **哈希表（Hash Map）**：提供 O(1) 时间复杂度的快速访问。

组合起来的结构如下：

```text
Hash Map  <key -> node>
   |
   V
Double Linked List
[most recent] <-> ... <-> [least recent]
```

---

### 🧩 Python 示例（使用 `OrderedDict`）

```python
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key):
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)  # 标记为最近使用
        return self.cache[key]

    def put(self, key, value):
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)  # 删除最久未使用的项
```

---

### ⏱ 时间复杂度

* `get()` 和 `put()` 操作都能实现 **O(1)** 时间复杂度。

---

### 🧪 应用场景

* 操作系统内存管理（页面置换）
* 数据库查询缓存
* Web 浏览器缓存
* CDN 边缘缓存策略
