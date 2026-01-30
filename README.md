---
# 🚀 Ultimate Data Structures Reference (C++)

A comprehensive, deep-dive guide into the world of Data Structures. This repository serves as a technical "Cheat Sheet" for developers looking to master the efficiency and implementation of data organization in C++.

---

## 📌 Table of Contents

1. [Classification of Data Structures](https://www.google.com/search?q=%23-classification-of-data-structures)
2. [Linear Data Structures](https://www.google.com/search?q=%23-linear-data-structures)
* [Arrays & Vectors](https://www.google.com/search?q=%231-arrays--vectors)
* [Linked Lists](https://www.google.com/search?q=%232-linked-lists)
* [Stacks](https://www.google.com/search?q=%233-stacks)
* [Queues](https://www.google.com/search?q=%234-queues)


3. [Non-Linear Data Structures](https://www.google.com/search?q=%23-non-linear-data-structures)
* [Hash Tables (Maps)](https://www.google.com/search?q=%231-hash-tables-unordered-maps)
* [Trees](https://www.google.com/search?q=%232-trees)
* [Graphs](https://www.google.com/search?q=%233-graphs)


4. [Time Complexity Analysis](https://www.google.com/search?q=%23-time-complexity-analysis)

---

## 🗂️ Classification of Data Structures

Data structures are categorized based on how elements are organized and accessed:

1. **Primitive:** Basic types like `int`, `char`, `float`.
2. **Linear:** Elements form a sequence (one-to-one relationship).
3. **Non-Linear:** Elements are organized hierarchically or in a network (one-to-many or many-to-many).

---

## 📏 Linear Data Structures

### 1. Arrays & Vectors

**Concept:** Elements are stored in contiguous memory locations. `std::vector` is the dynamic version of an array in C++.

```cpp
#include <vector>
#include <iostream>

void arrayExample() {
    // Dynamic array (Vector)
    std::vector<int> nums = {10, 20, 30};
    nums.push_back(40); // Add to end O(1)
    
    // Random access
    std::cout << nums[1]; // Access index 1 O(1)
}

```

### 2. Linked Lists

**Concept:** A sequence of nodes where each node contains a value and a pointer.

* **Singly:** Pointer to the next node.
* **Doubly:** Pointers to both next and previous nodes.

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Simple usage
Node* head = new Node(1);
head->next = new Node(2);

```

### 3. Stacks

**Concept:** **LIFO** (Last-In, First-Out). Elements are added and removed from the same end (the top).

```cpp
#include <stack>

void stackExample() {
    std::stack<int> s;
    s.push(100); // Push O(1)
    s.push(200);
    int topElement = s.top(); // Look at top
    s.pop();     // Remove top O(1)
}

```

### 4. Queues

**Concept:** **FIFO** (First-In, First-Out). Elements are added at the rear and removed from the front.

```cpp
#include <queue>

void queueExample() {
    std::queue<int> q;
    q.push(1); // Enqueue O(1)
    q.push(2);
    q.pop();   // Dequeue O(1)
}

```

---

## 🌿 Non-Linear Data Structures

### 1. Hash Tables (Unordered Maps)

**Concept:** Uses a **Hash Function** to map unique keys to values for near-instant retrieval.

```cpp
#include <unordered_map>
#include <string>

void mapExample() {
    std::unordered_map<std::string, int> studentGrades;
    studentGrades["Alice"] = 95; // Insert O(1)
    
    if (studentGrades.find("Alice") != studentGrades.end()) {
        // Found key O(1) average
    }
}

```

### 2. Trees

**Concept:** A hierarchical structure. The **Binary Search Tree (BST)** is a common variant where left < root < right.

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

```

### 3. Graphs

**Concept:** A collection of nodes (Vertices) and connections (Edges).

* **Adjacency List:** Efficient for sparse graphs.
* **Adjacency Matrix:** Efficient for dense graphs.

```cpp
#include <vector>
#include <list>

// Adjacency List Representation
std::vector<std::list<int>> adjList(5); // Graph with 5 vertices
void addEdge(int u, int v) {
    adjList[u].push_back(v); 
}

```

---

## 📊 Time Complexity Analysis

Understanding **Big O** is crucial for choosing the right data structure.

| Data Structure | Access | Search | Insertion | Deletion |
| --- |--------|--------|-----------|----------|
| **Array** | $O(1)$ | $O(n)$ | $O(n)$    | $O(n)$   |
| **Vector** | $O(1)$ | $O(n)$ | $O(1)^*$  | $O(n)$   |
| **Linked List** | $O(n)$ | $O(n)$ | $O(1)$    | $O(1)$   |
| **Stack / Queue** | $O(n)$ | $O(n)$ | $O(1)$    | $O(1)$   |
| **Hash Table** | $N/A$  | $O(1)$ | $O(1)$    | $O(1)$   |
| **BST (Balanced)** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$    | $O(\log n)$   |

---

## 🛠️ Setup & Usage

1. **Clone the repo:** `git clone https://github.com/yourusername/repo-name.git`
2. **Compiler:** Ensure you have `g++` (GCC) installed.
3. **Run examples:** `g++ -std=c++17 main.cpp -o out && ./out`

---

⭐ **Star this repository if you find these references helpful!**
