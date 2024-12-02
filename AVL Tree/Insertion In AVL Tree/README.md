#### 🔗 Prerequisites: 
- Problem: [Insert Node Into A BST](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)  
- Solution: [Don't Skip Approach 2, Because I'll Be Using The Same Code For AVL Tree Insertion](https://leetcode.com/problems/insert-into-a-binary-search-tree/solutions/6105646/three-solutions-brute-optimal-readable-cpp-code/)

---

## 🌳 Cases of Unbalancing in AVL Tree

The following cases of unbalancing occur based on the side of insertion:

### 1. LL Case (Left-Left)
- Perform **right rotation** with respect to the root node (top node).

### 2. RR Case (Right-Right)
- Perform **left rotation** with respect to the root node (top node).

### 3. LR Case (Left-Right)
1. Perform **left rotation** with respect to the middle node of the root node (top node).
2. Perform **right rotation** with respect to the root node (top node).

### 4. RL Case (Right-Left)
1. Perform **right rotation** with respect to the middle node of the root node (top node).
2. Perform **left rotation** with respect to the root node (top node).

***

## 🔍 Determining the Case of Unbalancing

To identify which case of unbalancing has occurred for any node:

### 1. **Balance Factor > 1**
- The node is unbalanced from the **left side**.
- Check the side of insertion from the left child:
  1. **Key < rootNode->left->data** → **LL Case**
  2. **Key > rootNode->left->data** → **LR Case**

### 2. **Balance Factor < -1**
- The node is unbalanced from the **right side**.
- Check the side of insertion from the right child:
  1. **Key > rootNode->right->data** → **RR Case**
  2. **Key < rootNode->right->data** → **RL Case**

***

## ⏱️ Time Complexity of AVL Tree Operations

### Worst-Case Scenario:
- The **maximum depth** of an AVL tree is **Log₂(N)**.
- Operations like **insertion**, **deletion**, and **searching** may require traversing to the deepest node.
- Since the maximum depth is **Log₂(N)**, the **time complexity** for these operations is also **Log₂(N)**.

### Key Insight:
- The time complexity directly depends on the maximum depth of the AVL tree.
