以下是 C++ STL 中**所有主要容器的常用函数详解**，覆盖 **顺序容器、关联容器、无序容器、适配器** 四大类。每个容器部分都分为：

1. 常用操作函数（插入、删除、查找、遍历等）
2. 使用示例（标准格式）
3. 特殊说明（如效率差异、使用注意）

---

## 🔹 1. `vector<T>` – 动态数组

### ✅ 常用函数

| 函数                     | 说明                          |
| ---------------------- | --------------------------- |
| `push_back(val)`       | 在尾部添加元素                     |
| `pop_back()`           | 删除尾部元素                      |
| `at(i)` / `operator[]` | 访问第 i 个元素，`at` 有越界检查        |
| `front()` / `back()`   | 返回第一个/最后一个元素                |
| `insert(pos, val)`     | 在指定位置插入                     |
| `erase(pos)`           | 删除指定位置元素                    |
| `clear()`              | 清空所有元素                      |
| `size()` / `empty()`   | 获取当前元素个数 / 是否为空             |
| `resize(n)`            | 改变容器大小                      |
| `begin()` / `end()`    | 获取迭代器，适用于 `for(auto x : v)` |

### 🧪 示例

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
v.insert(v.begin() + 1, 10);
v.erase(v.begin());
for (int x : v) cout << x << " ";
```

---

## 🔹 2. `deque<T>` – 双端队列

### ✅ 常用函数（大多和 `vector` 类似）

| 函数                           | 说明     |
| ---------------------------- | ------ |
| `push_front(val)`            | 头部插入   |
| `push_back(val)`             | 尾部插入   |
| `pop_front()` / `pop_back()` | 删除两端元素 |
| `front()` / `back()`         | 访问首尾元素 |

---

## 🔹 3. `list<T>` – 双向链表

### ✅ 常用函数

| 函数                             | 说明             |
| ------------------------------ | -------------- |
| `push_front()` / `push_back()` | 头尾插入           |
| `pop_front()` / `pop_back()`   | 头尾删除           |
| `insert(it, val)`              | 在迭代器位置前插入      |
| `erase(it)`                    | 删除指定位置         |
| `remove(val)`                  | 删除所有等于 val 的元素 |
| `sort()` / `reverse()`         | 排序 / 反转        |

---

## 🔹 4. `forward_list<T>` – 单向链表（节省内存）

### ✅ 常用函数

| 函数                      | 说明               |
| ----------------------- | ---------------- |
| `push_front(val)`       | 只能在前插入           |
| `pop_front()`           | 删除头部             |
| `insert_after(it, val)` | 在 it 之后插入        |
| `erase_after(it)`       | 删除 it 之后的元素      |
| `before_begin()`        | 返回首元素之前位置（必须使用它） |

---

## 🔹 5. `array<T, N>` – 固定大小数组（C++11）

### ✅ 常用函数

| 函数                   | 说明        |
| -------------------- | --------- |
| `at(i)`              | 带边界检查的访问  |
| `[]`                 | 普通访问      |
| `fill(val)`          | 全部赋值为 val |
| `front()` / `back()` | 访问头尾元素    |

---

## 🔹 6. `set<T>` – 自动排序 + 去重

### ✅ 常用函数

| 函数                 | 说明                 |
| ------------------ | ------------------ |
| `insert(val)`      | 插入元素               |
| `erase(val)`       | 删除某个值              |
| `find(val)`        | 查找值，返回迭代器或 `end()` |
| `count(val)`       | 检查某值是否存在（返回 0 或 1） |
| `lower_bound(val)` | ≥val 的最小值迭代器       |
| `upper_bound(val)` | >val 的最小值迭代器       |
| `begin()/end()`    | 遍历                 |

---

## 🔹 7. `map<Key, Value>` – 键值对 + 自动排序

### ✅ 常用函数

| 函数                   | 说明             |
| -------------------- | -------------- |
| `insert({key, val})` | 插入键值对          |
| `map[key] = val`     | 插入或更新          |
| `erase(key)`         | 删除 key         |
| `find(key)`          | 查找 key         |
| `count(key)`         | 是否存在（返回 0 或 1） |

---

## 🔹 8. `unordered_map<Key, Value>` – 无序键值对（哈希表）

### ✅ 常用函数（与 `map` 类似）

* `insert({key, value})`
* `erase(key)`
* `find(key)`
* `operator[]`：支持赋值访问
* `bucket_count()` / `load_factor()`：查看哈希桶信息（进阶）

⚠️ 注意：**Key 类型必须支持哈希函数 `std::hash`**，否则需要自定义。

---

## 🔹 9. `stack<T>` – 栈（适配器）

### ✅ 常用函数

| 函数          | 说明     |
| ----------- | ------ |
| `push(val)` | 压栈     |
| `pop()`     | 出栈     |
| `top()`     | 查看栈顶元素 |
| `empty()`   | 是否为空   |
| `size()`    | 当前元素个数 |

---

## 🔹 10. `queue<T>` – 队列（先进先出）

### ✅ 常用函数

| 函数          | 说明     |
| ----------- | ------ |
| `push(val)` | 入队（尾部） |
| `pop()`     | 出队（头部） |
| `front()`   | 查看队头   |
| `back()`    | 查看队尾   |

---

## 🔹 11. `priority_queue<T>` – 优先队列（默认大顶堆）

### ✅ 常用函数

| 函数                   | 说明          |
| -------------------- | ----------- |
| `push(val)`          | 插入          |
| `pop()`              | 弹出最大（或最小）元素 |
| `top()`              | 获取最大（或最小）值  |
| `empty()` / `size()` | 是否为空 / 数量   |

👉 可以通过自定义比较器实现小顶堆：

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## 📌 补充：遍历方式对比

所有容器均支持：

```cpp
for (auto it = c.begin(); it != c.end(); ++it) {}
for (auto& val : c) {}
```

---

如果你想要：

* 各容器的**速查表**或**操作性能对比图表**
* 用于**面试准备/刷题**的 STL 容器速记笔记
* 每个容器的**使用案例项目/题目推荐**

我可以继续提供对应内容。是否需要？


当然可以！下面我将为你提供：

---

## 📊 **STL 容器操作性能对比表**

| 操作        | `vector` | `deque` | `list`       | `set/map`        | `unordered_set/map`        | `stack` / `queue` | `priority_queue` |
| --------- | -------- | ------- | ------------ | ---------------- | -------------------------- | ----------------- | ---------------- |
| 末尾插入      | ✅ O(1)   | ✅ O(1)  | ✅ O(1)       | ❌ O(log n)       | ❌ O(1) (平均)                | ✅ O(1)            | ✅ O(log n)       |
| 头部插入      | ❌ O(n)   | ✅ O(1)  | ✅ O(1)       | ❌                | ❌                          | ✅ O(1)            | ❌                |
| 任意位置插入    | ❌ O(n)   | ❌ O(n)  | ✅ O(1)（需迭代器） | ❌                | ❌                          | ❌                 | ❌                |
| 查找元素      | ✅ O(1)   | ✅ O(1)  | ❌ O(n)       | ✅ O(log n)       | ✅ O(1)（平均）                 | ❌                 | ❌                |
| 访问第 i 个元素 | ✅ O(1)   | ✅ O(1)  | ❌            | ❌                | ❌                          | ❌                 | ❌                |
| 自动排序      | ❌        | ❌       | ❌            | ✅                | ❌                          | ❌                 | ✅（按优先级）          |
| 是否允许重复键   | ✅        | ✅       | ✅            | ❌（`multiset` 允许） | ❌（`unordered_multiset` 允许） | ✅                 | ❌                |
| 内存使用      | 小        | 中       | 高            | 高                | 高                          | 小                 | 中                |
| 线程安全      | ❌        | ❌       | ❌            | ❌                | ❌                          | ❌                 | ❌                |

---

## 🧠 STL 容器速记笔记

### 🧾 1. **顺序容器总结**

* `vector`: 动态数组，末尾操作快，**最常用**。
* `deque`: 双端数组结构，**头尾都快**。
* `list`: 双向链表，**插删快但查找慢**。
* `forward_list`: 单向链表，**内存最省**。
* `array`: C++11 固定长度数组，类似 `T arr[N]`，**无扩容**。

📌 优选场景：

* 快速访问：`vector`, `array`
* 快速插删：`list`, `deque`

---

### 🧾 2. **关联容器速记**

* `set`: 自动排序+去重。
* `multiset`: 自动排序+可重复。
* `map`: `key -> value`，按 key 排序。
* `multimap`: key 可重复。

🌟 全部底层都是 **红黑树**，支持：

```cpp
lower_bound(), upper_bound(), insert(), erase(), find()
```

---

### 🧾 3. **无序关联容器速记**

* `unordered_set`, `unordered_map`: 基于哈希表，**O(1) 平均查找**。
* `unordered_multiset`, `unordered_multimap`: 支持重复键。

⚠️ 注意：

* 无序，**不排序**。
* 需要 `Key` 类型支持 `hash()`。

---

### 🧾 4. **适配器容器速记**

* `stack`: 后进先出（LIFO）
* `queue`: 先进先出（FIFO）
* `priority_queue`: 默认大顶堆，支持小顶堆

```cpp
priority_queue<int, vector<int>, greater<int>> min_heap;
```

---

### 📌 容器使用口诀（助记）

```
增删改查记效率，序列vector最常用。
双端插删选deque，链表list随意游。
排序查找map/set，唯一键值靠tree修。
查找更快unordered，哈希结构快如牛。
堆栈队列属适配，接口有限最简便。
```

---

## 📚 推荐面试/实战备查顺序（最常用 ➜ 最特殊）

1. `vector`
2. `unordered_map` / `map`
3. `set` / `unordered_set`
4. `stack` / `queue` / `priority_queue`
5. `deque`
6. `list` / `forward_list`
7. `multimap` / `multiset`

---

