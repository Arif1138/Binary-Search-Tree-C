# Binary Search Tree in C

This project demonstrates a binary search tree (BST) implemented in C. It supports inserting values, finding the minimum and maximum values, deleting nodes, and printing the tree using an in-order traversal.

## Features

- Insert integer values into the BST.
- Find the minimum and maximum nodes.
- Delete nodes with no children, one child, or two children.
- Print the values in ascending order with an in-order traversal.

## Build

Compile the source file with a C compiler:

```sh
gcc BinarySearchTree.c -o BinarySearchTree
```

## Run

On Linux or macOS:

```sh
./BinarySearchTree
```

On Windows:

```powershell
.\BinarySearchTree.exe
```

The `main` function builds a sample tree, prints it, then demonstrates deleting a leaf node, a node with one child, and a node with two children.

## Implementation

- `createNode` allocates and initializes a node.
- `insert` adds a value while preserving the BST ordering rules.
- `findMin` and `findMax` return the smallest and largest nodes in a subtree.
- `deleteNode` removes a value and reconnects the affected subtree.
- `inorder` visits the left subtree, the current node, and then the right subtree, producing sorted output.

Duplicate values are ignored by `insert`.
