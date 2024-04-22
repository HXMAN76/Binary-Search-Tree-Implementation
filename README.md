
# Binary Search Tree 

A binary search tree (BST) is a data structure used for organizing and storing a set of elements in memory. It is composed of nodes, where each node contains a key (or value) and optionally links to two child nodes: a left child and a right child. The BST has the following properties:

1. **Binary Tree Structure**: Each node has at most two children, referred to as the left child and the right child.

2. **Ordering Property**: For every node in the tree, all keys in the left subtree are less than the node's key, and all keys in the right subtree are greater than the node's key. This property ensures efficient searching, insertion, and deletion operations.

3. **No Duplicates**: Typically, BSTs do not allow duplicate keys. If a duplicate key is inserted, it can either be ignored or handled in a specific way depending on the implementation.

The ordering property of a BST allows for efficient searching. When searching for a key in a BST, you start at the root node and compare the key you're searching for with the current node's key. If the key is equal to the current node's key, you've found the element. If the key is less than the current node's key, you move to the left child; if it's greater, you move to the right child. This process continues recursively until the key is found or until you reach a leaf node (a node with no children), indicating that the key is not present in the tree.

BSTs are widely used in computer science and are the foundation for many other data structures and algorithms, such as balanced binary search trees (e.g., AVL trees, red-black trees) and priority queues. They provide efficient average-case performance for searching, insertion, and deletion operations, with time complexity of O(log n), where n is the number of elements in the tree. However, in the worst-case scenario, the time complexity of these operations can degrade to O(n), especially if the tree becomes unbalanced.


## Authors

- [@Hari Heman](https://www.github.com/MAD-MAN-HEMAN)
- [@Raghav](https://www.github.com/Rag-795)



#
[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

