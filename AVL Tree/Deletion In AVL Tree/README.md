## 🌲 Cases of Unbalancing in AVL Tree During Deletion

The deletion process in an AVL Tree can lead to unbalancing when nodes are removed. The unbalanced cases are resolved based on the **balance factor** of the node and the structure of its child nodes.

### Unbalancing Cases:

---

### 1. **LL Case (Left-Left)**
- **Condition**: 
  - Balance factor of the current node (`BF > 1`). Current node is the unbalanced node.
  - Balance factor of the left child (`BF >= 0`).
- **Fix**: Perform a **right rotation** with respect to the unbalanced node.

---

### 2. **RR Case (Right-Right)**
- **Condition**: 
  - Balance factor of the current node (`BF < -1`). Current node is the unbalanced node.
  - Balance factor of the right child (`BF <= 0`).
- **Fix**: Perform a **left rotation** with respect to the unbalanced node. 

---

### 3. **LR Case (Left-Right)**
- **Condition**: 
  - Balance factor of the current node (`BF > 1`). Current node is the unbalanced node.
  - Balance factor of the left child (`BF < 0`).
- **Fix**:
  1. Perform a **left rotation** with respect to the left child of the unbalanced node.
  2. Perform a **right rotation** with respect to the unbalanced node. 

---

### 4. **RL Case (Right-Left)**
- **Condition**: 
  - Balance factor of the current node (`BF < -1`). Current node is the unbalanced node.
  - Balance factor of the right child (`BF > 0`).
- **Fix**:
  1. Perform a **right rotation** with respect to the right child of the unbalanced node.
  2. Perform a **left rotation** with respect to the unbalanced node.

---

---

## ⏱️ Time Complexity of AVL Tree Operations

The time complexity of any operation depends on the **height** of the AVL tree.

### Key Details:
- The height of an AVL tree is **Log₂(N)**.
- Time complexities for key operations:
  - **Searching**: **O(Log₂(N))**
  - **Update**: **O(Log₂(N))**
  - **Insert**: **O(Log₂(N))**
  - **Delete**: **O(Log₂(N))**

---

### Specific Operation:
- The **getLeftMostNode()** method, used in the **deletion code**, takes **O(H)** time, where **H = Log₂(N)**.
- Overall time complexity: **O(Log₂(N))**

---

