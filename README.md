# 📚 DSA-Programs

Welcome to the **DSA-Programs** repository! This project offers a comprehensive collection of Data Structures and Algorithms (DSA) implemented in various programming languages. Whether you're a beginner or an experienced developer, you'll find valuable resources to enhance your understanding of DSA concepts.

## 🚀 Features

- **Array ADT**: Basic operations on arrays.
- **Matrix**: Matrix manipulations and operations.
- **Linked Lists**: Singly, Doubly, and Circular Linked Lists.
- **Stacks and Queues**: Implementation of stacks, queues, and their variations.
- **Trees**: Binary Trees, Binary Search Trees, AVL Trees, and Heaps.
- **Sorting Algorithms**: Various sorting techniques.
- **Hashing**: Hash table implementations.
- **Graphs**: Graph algorithms and representations.

## 📂 Project Structure

```plaintext
├── .gitignore
├── .vscode/
│   ├── launch.json
│   ├── settings.json
│   └── tasks.json
├── 01. Array ADT/
├── 02. Matrix/
├── 03. Linked Lists/
├── 04. Circular Linked Lists/
├── 05. Doubly Linked Lists/
├── 06. Circular Doubly Linked Lists/
├── 07. Stack/
├── 08. Circular Stack/
├── 09. Queue/
├── 10. Circular Queue/
├── 11. Double Ended Queue/
├── 12. Priority Queue/
├── 13. Binary Tree/
├── 14. Binary Search Tree/
├── 15. AVL Tree/
├── 16. Heap/
├── 17. Sorting Algorithms/
├── 18. Hashing/
├── 19. Graphs/
├── Complete Classes/
├── Infix Postfix/
├── LICENSE
├── Parentheses Checking/
└── README.md
```

## 🛠️ Installation

To get started with this project, clone the repository:

```bash
git clone https://github.com/your-username/DSA-Programs.git
cd DSA-Programs
```

## 📖 Usage

Each directory contains programs related to specific data structures or algorithms. Navigate to the respective directory to explore the implementations.

## 📚 Data Structures Overview

Below is an overview of each data structure included in this repository, accompanied by both ASCII diagrams and illustrative images for better understanding.

### 1. Array ADT

An array is a collection of elements identified by index or key. It is one of the simplest data structures where each data element can be accessed directly by its index.

**ASCII Diagram:**

```
Index:   0   1   2   3   4
        +---+---+---+---+---+
Array:  |10 |20 |30 |40 |50 |
        +---+---+---+---+---+
```

**Illustrative Image:**

![Array](https://www.geeksforgeeks.org/wp-content/uploads/2021/06/array-660x330.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/array-data-structure/)_

### 2. Matrix

A matrix is a two-dimensional array of numbers arranged in rows and columns.

**ASCII Diagram:**

```
Matrix:
    1   2   3
    4   5   6
    7   8   9
```

**Illustrative Image:**

![Matrix](https://www.geeksforgeeks.org/wp-content/uploads/Matrix.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/matrix/)_

### 3. Linked Lists

A linked list is a linear data structure where each element is a separate object, known as a node. Each node contains data and a reference (or link) to the next node in the sequence.

**ASCII Diagram:**

```
Head
 |
 v
+------+    +------+    +------+
| Data |--->| Data |--->| Data |--->NULL
+------+    +------+    +------+
```

**Illustrative Image:**

![Linked List](https://www.geeksforgeeks.org/wp-content/uploads/singly-linked-list.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)_

### 4. Circular Linked Lists

A variation of a linked list where the last node points back to the first node, forming a circle.

**ASCII Diagram:**

```
       +------+    +------+    +------+
Head-->| Data |--->| Data |--->| Data |
 ^     +------+    +------+    +------+
 |                                   |
 +-----------------------------------+
```

**Illustrative Image:**

![Circular Linked List](https://www.geeksforgeeks.org/wp-content/uploads/CircularLinkedList.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/circular-linked-list/)_

### 5. Doubly Linked Lists

A linked list where each node contains a reference to both the next and the previous node, allowing traversal in both directions.

**ASCII Diagram:**

```
NULL<--+------+<-->+------+<-->+------+-->NULL
       | Data |    | Data |    | Data |
       +------+    +------+    +------+
```

**Illustrative Image:**

![Doubly Linked List](https://www.geeksforgeeks.org/wp-content/uploads/DLL1.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/doubly-linked-list/)_

### 6. Circular Doubly Linked Lists

A combination of circular and doubly linked lists where the last node points back to the first node, and each node has references to both the next and previous nodes.

**ASCII Diagram:**

```
       +------+<-->+------+<-->+------+
Head<->| Data |<-->| Data |<-->| Data |
 ^     +------+    +------+    +------+
 |                                   |
 +-----------------------------------+
```

**Illustrative Image:**

![Circular Doubly Linked List](https://www.geeksforgeeks.org/wp-content/uploads/CircularDoublyLinkedList.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/)_

### 7. Stack

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. Elements are added (pushed) and removed (popped) from the same end, referred to as the top.

**ASCII Diagram:**

```
Stack:
+------+
| Data | <- Top
+------+
| Data |
+------+
| Data |
+------+
```

**Illustrative Image:**

![Stack](https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/stack.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/)_

### 8. Circular Stack

A circular stack is a variation of the standard stack where the end of the stack wraps around to the beginning.

**ASCII Diagram:**

```

+------+    +------+    +------+
| Data |--->| Data |--->| Data |
+------+    +------+    +------+
  ^                        |
  |                        v
+------+    +------+    +------+
| Data |--->| Data |--->| Data |
+------+    +------+    +------+
```

**Illustrative Image:**

![Circular Stack](https://www.geeksforgeeks.org/wp-content/uploads/CircularStack.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/circular-stack/)_

### 9. Queue

A queue is a linear data structure that follows the First In First Out (FIFO) principle. Elements are added (enqueued) at the rear and removed (dequeued) from the front.

**ASCII Diagram:**

```
Queue:
Front                    Rear
    |                       |
    v                       v
+-----+  +-----+  +-----+  +-----+
|Data |  |Data |  |Data |  |Data |
+-----+  +-----+  +-----+  +-----+
```

**Illustrative Image:**

![Queue](https://www.geeksforgeeks.org/wp-content/uploads/Queue.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/queue-data-structure/)_

### 10. Circular Queue

A circular queue is a variation of the standard queue where the last position is connected back to the first position to make a circle.

**ASCII Diagram:**

```
Circular Queue:
Front                    Rear
    |                       |
    v                       v
+-----+  +-----+  +-----+  +-----+
|Data |  |Data |  |Data |  |Data |
+-----+  +-----+  +-----+  +-----+
    ^                       |
    |                       v
+-----+  +-----+  +-----+  +-----+
|Data |  |Data |  |Data |  |Data |
+-----+  +-----+  +-----+  +-----+
```

**Illustrative Image:**

![Circular Queue](https://www.geeksforgeeks.org/wp-content/uploads/CircularQueue.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/)_

### 11. Double Ended Queue

A double-ended queue (deque) is a linear data structure that allows insertion and deletion of elements from both ends.

**ASCII Diagram:**

```
Deque:
Front                    Rear
    |                       |
    v                       v
+-----+  +-----+  +-----+  +-----+
|Data |  |Data |  |Data |  |Data |
+-----+  +-----+  +-----+  +-----+
```

**Illustrative Image:**

![Deque](https://www.geeksforgeeks.org/wp-content/uploads/Deque.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/)_

### 12. Priority Queue

A priority queue is a special type of queue in which each element is associated with a priority and elements are served based on their priority.

**ASCII Diagram:**

```
Priority Queue:
+-----+  +-----+  +-----+  +-----+
|High |  |Med  |  |Low  |  |Low  |
|Priority|Priority|Priority|Priority|
+-----+  +-----+  +-----+  +-----+
```

**Illustrative Image:**

![Priority Queue](https://www.geeksforgeeks.org/wp-content/uploads/PriorityQueue.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)_

### 13. Binary Tree

A binary tree is a tree data structure in which each node has at most two children, referred to as the left child and the right child.

**ASCII Diagram:**

```
        Binary Tree:
            1
           / \
          2   3
         / \ / \
        4  5 6  7
```

**Illustrative Image:**

![Binary Tree](https://www.geeksforgeeks.org/wp-content/uploads/BinaryTree.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/binary-tree-data-structure/)_

### 14. Binary Search Tree

A binary search tree (BST) is a binary tree in which each node has a value greater than all the values in its left subtree and less than all the values in its right subtree.

**ASCII Diagram:**

```
        Binary Search Tree:
            4
           / \
          2   6
         / \ / \
        1  3 5  7
```

**Illustrative Image:**

![Binary Search Tree](https://www.geeksforgeeks.org/wp-content/uploads/BST.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)_

### 15. AVL Tree

An AVL tree is a self-balancing binary search tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.

**ASCII Diagram:**

```
        AVL Tree:
            30
           /  \
          20   40
         /  \
        10   25
```

**Illustrative Image:**

![AVL Tree](https://www.geeksforgeeks.org/wp-content/uploads/AVLTree.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)_

### 16. Heap

A heap is a special tree-based data structure that satisfies the heap property. In a max heap, for any given node I, the value of I is greater than or equal to the values of its children.

**ASCII Diagram:**

```
        Max Heap:
            10
           /  \
          9    8
         / \  / \
        7  6 5  4
```

**Illustrative Image:**

![Heap](https://www.geeksforgeeks.org/wp-content/uploads/Heap.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/heap-data-structure/)_

### 17. Sorting Algorithms

Sorting algorithms are methods of reorganizing a large number of items into a specific order, such as ascending or descending.

**Illustrative Image:**

![Sorting Algorithms](https://www.geeksforgeeks.org/wp-content/uploads/Sorting.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)_

### 18. Hashing

Hashing is a technique used to uniquely identify a specific object from a group of similar objects. A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values.

**ASCII Diagram:**

```
Hash Table:
+-----+-----+-----+-----+-----+
|Index| Key |Value| Key |Value|
+-----+-----+-----+-----+-----+
|  0  |  1  |  20 |  2  |  30 |
+-----+-----+-----+-----+-----+
```

**Illustrative Image:**

![Hashing](https://www.geeksforgeeks.org/wp-content/uploads/Hashing.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/hashing-data-structure/)_

### 19. Graphs

A graph is a collection of nodes, called vertices, and the connections between them, called edges. Graphs can be used to model many types of relations and processes in physical, biological, social, and information systems.

**ASCII Diagram:**

```
Graph:
      A
     / \
    B---C
     \ / \
      D---E
```

**Illustrative Image:**

![Graph](https://www.geeksforgeeks.org/wp-content/uploads/Graph.png)

_Source: [GeeksforGeeks](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)_

### 🛠️ Installation

To get started with this project, clone the repository:

```bash
git clone https://github.com/your-username/DSA-Programs.git
cd DSA-Programs
```

### 📖 Usage

Each directory contains programs related to specific data structures or algorithms. Navigate to the respective directory to explore the implementations.

### 🤝 Contributing

Contributions are welcome! If you have any improvements or new implementations, feel free to open a pull request.

- Fork the repository.
- Create a new branch (git checkout -b feature-branch).
- Commit your changes (git commit -m 'Add some feature').
- Push to the branch (git push origin feature-branch).
- Open a pull request.

### 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

📧 Contact

if you have any questions or suggestions, feel free to reach out to us at ijlalahmad845@gmail.com
