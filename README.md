
# Code_For_Algorithm

> 个人数据结构与算法学习代码仓库（C++ 实现）

## ⚠️ 说明

本仓库是作者在学习 **数据结构与算法** 课程过程中，**边学边写**的个人练习代码合集。因此：

- **不保证全面性**：代码随课程进度编写，部分知识点可能未覆盖或仅涉及基础实现，并非一份完整的数据结构与算法知识体系。
- **不保证通用性**：部分实现以理解原理为主要目的，未做工程化封装和边界情况处理，可能存在 trivial 的实现方式，不适合直接用于生产环境。
- **按课程路线组织**：目录结构和内容选择均基于课程大纲，而非通用的算法学习路线（如 LeetCode 分类或面试考点），请自行甄别参考。

> 如果你正在系统学习数据结构与算法，建议配合经典教材（如《数据结构（C 语言版）》《算法导论》）及在线评测平台（如 LeetCode、洛谷）一同使用。

## 简介

所有代码使用 **C++** 编写，涵盖线性表、栈与队列、树与二叉树、图论、排序与查找、外部排序、文件索引以及部分经典算法问题。每个模块均包含可直接编译运行的 `.cpp` 源文件。

## 目录结构

```
Code_For_Algorithm/
├── 线性表/
│   ├── 链表/
│   │   └── LinkedList.cpp            # 链表实现（头插法、尾插法、按位查找等）
│   └── 顺序表/
│       └── sequential_list.cpp       # 顺序表实现
│
├── 栈的应用/
│   └── ParentheseValidityJudgement/
│       └── ParenValidityJudgement.cpp # 括号匹配合法性判断
│
├── 二叉树/
│   ├── binaryTree.cpp                # 二叉树基本操作（度统计、遍历等）
│   ├── binaryTreeBasic.cpp           # 二叉树基础实现
│   ├── huffmanTree.cpp               # 哈夫曼树
│   ├── 二叉搜索树.cpp                 # 二叉搜索树
│   ├── binarySearchTree/
│   │   └── binarySearchTree.cpp      # 二叉搜索树（另一版本）
│   ├── 堆与优先队列.cpp               # 堆与优先队列
│   ├── 堆与优先队列(小顶堆).cpp       # 小顶堆实现
│   ├── 大顶堆.cpp                     # 大顶堆实现
│   └── 数组实现完全二叉树.cpp         # 数组方式实现完全二叉树
│
├── 树/
│   ├── ArrTree.cpp                   # 数组实现的树
│   ├── DegreeTree.cpp                # 度表示的树
│   ├── DoubleTagTree.cpp             # 双标记树
│   └── Disjoint_Set_Union.cpp        # 并查集（路径压缩 + 按秩合并）
│
├── 图/
│   ├── bfsGraph.cpp                  # 图的广度优先搜索（BFS）
│   ├── dfsGraph.cpp                  # 图的深度优先搜索（DFS）
│   ├── Dijkstra.cpp                  # Dijkstra 最短路径算法
│   ├── Floyd.cpp                     # Floyd 多源最短路径
│   ├── Floyd_WithPath.cpp            # Floyd 算法（含路径记录）
│   ├── Kruskal.cpp                   # Kruskal 最小生成树
│   └── Prim.cpp                      # Prim 最小生成树
│
├── 排序/
│   ├── sort.cpp                      # 多种排序算法集合（插入、冒泡、选择、快速等）
│   ├── mergeSort.cpp                 # 归并排序
│   ├── CountSort.cpp                 # 计数排序
│   ├── RadixSort.cpp                 # 基数排序
│   ├── bucketSort.cpp                # 桶排序
│   ├── ImproveSort.cpp               # 改进排序
│   ├── ListSort.cpp                  # 链表排序
│   └── findKgreatestNum.cpp          # 查找第 K 大数
│
├── 外排序/
│   ├── LoserTree/
│   │   └── LoserTree.cpp             # 败者树（多路归并）
│   ├── ReplaceSelectionSort/
│   │   ├── ReplaceSelectionSort.cpp  # 置换-选择排序
│   │   ├── input.txt                 # 输入测试数据
│   │   └── output.txt                # 输出结果
│   ├── ReplaceSelectionByclass/
│   │   ├── ReplaceSelectionSort.cpp  # 置换-选择排序（类封装版）
│   │   ├── input.txt
│   │   └── output.txt
│   ├── outSort_twoWay/
│   │   └── outSort_twoWay.cpp        # 二路外部归并排序
│   └── Find'KthLargest/
│       └── FindKthLargest.cpp        # 海量数据中查找第 K 大
│
├── 检索/
│   ├── sequential search/
│   │   └── sequentialSearch.cpp      # 顺序查找
│   └── HashSearch/
│       └── hashSearch.cpp            # 哈希查找
│
├── 文件检索/
│   ├── BTree/
│   │   └── BTree.cpp                 # B 树实现
│   └── BPlusTree/
│       └── BPlusTree.cpp             # B+ 树实现（含范围查询）
│
├── KMP/
│   ├── kmp一般解法.cpp               # KMP 字符串匹配（next 数组）
│   └── kmp特殊解法.cpp               # KMP 改进版（nextval 数组）
│
├── 单调栈类问题/
│   └── 矩形最大面积.cpp              # 单调栈 → 直方图最大矩形面积
│
├── 单调队列/
│   └── 滑动窗口.cpp                  # 单调队列 → 滑动窗口最大值
│
├── 接雨水/
│   ├── 单调栈.cpp                    # 接雨水（单调栈解法）
│   └── 双指针维护.cpp                # 接雨水（双指针解法）
│
└── .gitignore                        # Git 忽略规则（Visual Studio）
```

## 技术栈

- **语言**：C++（部分使用 C++11/17 特性，如 `auto`、结构化绑定、`emplace_back` 等）
- **开发环境**：Visual Studio（参见 `.gitignore`）

## 快速开始

每个 `.cpp` 文件均为独立可编译单元，使用任意 C++ 编译器即可运行：

```bash
# 以 Dijkstra 最短路径为例
g++ -std=c++17 -o dijkstra 图/Dijkstra.cpp
./dijkstra

# 编译排序算法示例
g++ -std=c++17 -o sort 排序/sort.cpp
./sort
```

> 推荐使用支持 C++17 的编译器（GCC 8+ / Clang 7+ / MSVC 2019+）。

## 课程学习路径（仅供参考）

以下顺序大致对应作者课程的学习进度，**不代表通用学习路线**：

1. **线性表**：顺序表 → 链表
2. **栈与队列**：括号匹配 → 单调栈 / 单调队列问题
3. **树与二叉树**：二叉树基础 → 二叉搜索树 → 哈夫曼树 → 堆与优先队列 → 并查集
4. **图论**：BFS / DFS → 最小生成树（Prim、Kruskal）→ 最短路径（Dijkstra、Floyd）
5. **排序**：内部排序算法 → 外部排序（败者树、置换-选择排序）
6. **检索**：顺序查找 → 哈希查找 → B 树 / B+ 树索引
7. **字符串匹配**：KMP 算法

## 已知不足与待完善

- 缺少部分常见数据结构（如跳表、红黑树、AVL 树、Trie 等）
- 缺少部分经典算法（如拓扑排序、强连通分量、网络流、动态规划专题等）
- 部分代码缺少详细的边界测试和异常处理
- 排序算法未统一接口，各文件风格存在差异

欢迎提出改进建议或补充缺失内容。

## 许可证

本项目仅用于个人学习目的。
```

---

主要改动点：

1. **新增 `⚠️ 说明` 章节**：明确标注这是边学边写的个人练习代码，不保证全面性、通用性，按课程路线组织，非通用学习标准，并给出了配合教材和 OJ 平台使用的建议。
2. **学习路径标题加入"仅供参考"**：强调是课程进度，不代表通用路线。
3. **新增 `已知不足与待完善` 章节**：诚实列出缺了什么（跳表、红黑树、拓扑排序、DP 等），这样读者一看就知道范围边界在哪。
4. 去掉了过于"正式项目"的"贡献"章节，保留许可声明。

你可以直接复制以上内容替换当前空的 `README.md`，或者告诉我需要调整的地方！