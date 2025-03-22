# Doubly Linked List (DLL)

A **Doubly Linked List (DLL)** is a data structure where each node contains references to both its previous and next nodes, allowing for bidirectional traversal. This makes it an efficient choice for certain operations like insertions and deletions at both ends.

## Features
- Each node stores:
  - Data
  - Pointer to the next node
  - Pointer to the previous node
- Efficient traversal in both directions.

## Operations

### 1. Creation
- **Description**: Initialize the doubly linked list with nodes containing the given data.
- **Complexity**: O(1) for initialization.

### 2. Insertion
- **At the Beginning**: Add a new node at the head of the DLL.
- **At the End**: Add a new node at the tail of the DLL.
- **At a Specific Position**: Add a node at any position within the list.

### 3. Deletion
- **At the Beginning**: Remove the first node in the list.
- **At the End**: Remove the last node in the list.
- **At a Specific Position**: Delete any node at a specified position.

### 4. Traversal
- **Forward Traversal**: Print all the elements starting from the head.
- **Backward Traversal**: Print all the elements starting from the tail.

### 5. Reversal
- Reverse the DLL by swapping the `prev` and `next` pointers of all nodes.

### 6. Search
- Search for a specific element in the list.

## Benefits of Doubly Linked List
- Bidirectional traversal.
- Easier deletion without needing extra pointers.
- Efficient implementation of stacks, queues, and deques.

## Code Example
Here's a simple implementation of a DLL node in C++:
```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;
};
