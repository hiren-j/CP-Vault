# 🌳 Introduction to AVL Tree

## ❓ What is an AVL Tree?  
- **AVL Tree** stands for **Adelson-Velsky and Landis Tree**, named after the inventors.  
- It is a **self-balancing Binary Search Tree (BST)** that ensures operations like insertion, deletion, and search remain efficient.

---

## 🛠️ Why AVL Tree?  
- In a standard **BST**, the time complexity can become **O(N)** in the worst-case scenario (e.g., when the tree is skewed, like a linked list).  
- This means operations such as **insertion**, **search**, and **deletion** take **O(N)** time in the worst case.  
- An AVL Tree maintains a balanced structure, ensuring a time complexity of **O(Log₂(N))** for these operations.

---

## ⚖️ How does it maintain balance?  
- Each node in an AVL tree has a **balance factor**, calculated as:  
  ```text
  Balance Factor = Height of Left Subtree - Height of Right Subtree
- The tree is **balanced** if the balance factor of all the nodes is **-1, 0, or 1**.

## 🔄 Key Concept: Rotations  
To maintain balance after an insertion or deletion, **rotations** are performed:  

- **Left Rotation (LL)**  
- **Right Rotation (RR)**  
- **Left-Right Rotation (LR)**  
- **Right-Left Rotation (RL)**  

These rotations ensure the AVL tree remains balanced and efficient.  

---

**⚠️ Start learning from insertion and then move to deletion.**
