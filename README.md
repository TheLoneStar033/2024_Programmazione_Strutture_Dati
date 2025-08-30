
# 📚 Data Structures and Programming – Exercises

![Language](https://img.shields.io/badge/language-C-blue)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Status](https://img.shields.io/badge/status-educational-orange)

This repository contains a collection of exercises developed for the **Programming and Data Structures** course (Computer Science degree).  
All exercises are written in **C** and organized by topic with dedicated **Makefiles**.

---

## 📦 Contents

- **Stack** (array-based and linked list implementation)  
- **Queue** (FIFO, circular array, and linked list)  
- **Lists** (singly, doubly, circular)  
- **Trees** (binary trees, BST, traversals)  
- **Graphs** (adjacency lists, BFS/DFS)  
- **Miscellaneous** (recursion, memory management, etc.)  

---

## 🛠️ Compilation

Each folder includes a **Makefile**.  
To compile an exercise:

```bash
cd stack
make
./stack_test
````

To clean object files:

```bash
make clean
```

---

## 📑 Main Structures and Files

| Structure | Files                | Notes                                        |
| --------- | -------------------- | -------------------------------------------- |
| **Stack** | `stack.c`, `stack.h` | Implemented with arrays and linked lists     |
| **Queue** | `queue.c`, `queue.h` | Circular array and linked list               |
| **BST**   | `bst.c`, `bst.h`     | Binary search tree with insert/search/delete |
| **Graph** | `graph.c`, `graph.h` | Adjacency lists + BFS/DFS                    |

---

## 🧪 Tests

Some exercises include demo test files (`*_test.c`).
Run them after compilation to verify correct behavior:

```bash
./example_test
```



## 🎯 Goals

* Practice programming in **C**
* Understand and implement the main **data structures**
* Prepare for the **Programming and Data Structures** exam



## 📌 Notes

* This material is for **educational purposes only**.
* It does not represent official solutions, but personal practice exercises.
* Feel free to **fork, clone, and modify** the repository.


