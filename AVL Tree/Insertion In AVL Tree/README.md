#### 🔗 Prerequisites: 
- Problem: [Insert Node Into A BST](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)  
- Solution: [Don't Skip Approach 2, Because I'll Be Using The Same Code For AVL Tree Insertion](https://leetcode.com/problems/insert-into-a-binary-search-tree/solutions/6105646/three-solutions-brute-optimal-readable-cpp-code/)

---

## 🌳 Cases of Unbalancing in AVL Tree

The following cases of unbalancing occur based on the side of insertion:

### 1️⃣ **LL Case (Left-Left)**  
- **Condition**: A node is inserted into the left side of the left child of the unbalanced node.  
- **Fix**: Perform a **right rotation** with respect to the unbalanced node (root node / top node). 

#### Example:
```
Before Rotation                                After Right Rotation

     30                                                20
    /                                                 /  \
  20                                                10    30
 /
10
```

### 2️⃣ **RR Case (Right-Right)**  
- **Condition**: A node is inserted into the right side of the right child of the unbalanced node.  
- **Fix**: Perform a **left rotation** with respect to the unbalanced node (root node / top node).  

#### Example:
```
Before Rotation                             After Left Rotation
              
 10                                                20
   \                                              /  \
    20                                           10   30
      \
       30
```

### 3️⃣ **LR Case (Left-Right)**  
- **Condition**: A node is inserted into the right side of the left child of the unbalanced node.  
- **Fix**:  
  1. Perform a **left rotation** with respect to the middle node (left child) of the unbalanced node.  
  2. Perform a **right rotation** with respect to the unbalanced node (root node / top node).  

#### Example:
```
Before Rotation                           1. After Left Rotation                           2. After Right Rotation

   30                                              30                                                 20
  /                                               /                                                  /   \
10                                               20                                                10     30
  \                                             /
   20                                         10
```

### 4️⃣ **RL Case (Right-Left)**  
- **Condition**: A node is inserted into the left side of the right child of the unbalanced node.  
- **Fix**:  
  1. Perform a **right rotation** with respect to the middle node (right child) of the unbalanced node.  
  2. Perform a **left rotation** with respect to the unbalanced node (root node / top node).  

#### Example:
```
Before Rotation                           1. After Right Rotation                           2. After Left Rotation

10                                                10                                                   20
  \                                                 \                                                 /  \ 
   30                                                20                                             10    30
  /                                                    \
20                                                      30
```

***

## 🔍 Determining the Unbalancing Case Programmatically (Implementation Part)

As you've learned the different unbalancing cases (LL, RR, LR, RL) with diagrams above, let's see how you would determine the same for the **code part**.

### Steps to Determine the Unbalancing Case Programmatically:

1. **Calculate the Balance Factor**:
   - First, we calculate the balance factor of the node, which is the difference between the heights of the left and right subtrees:
     ```cpp
     int balanceFactor = height(node->left) - height(node->right);
     ```

2. **Check for Unbalancing**:
   - If the balance factor of a node is greater than 1 or less than -1, it indicates the node is unbalanced, and we need to perform rotations based on the specific case.

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
