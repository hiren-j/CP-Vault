## ⏱️ Time Complexity of AVL Tree Operations

The time complexity of any operation depends on the **height** of the AVL tree.

### Key Details:
- The height of an AVL tree is **Log₂(N)**.
- Time complexities for key operations:
  - **Searching**: **O(Log₂(N))**
  - **Update**: **O(Log₂(N))**
  - **Delete**: **O(Log₂(N))**

### Specific Operation:
- **getLeftMostNode()**:
  - Takes **O(H)** time, where **H = Log₂(N)**.
  - Overall time complexity: **O(Log₂(N))**
