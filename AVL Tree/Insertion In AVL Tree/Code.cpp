class AVLTree {
    // Method to find the height of the given node - O(1) & O(1)
    int getHeight(Node* rootNode) {
        if(!rootNode)
            return 0;

        return rootNode->height;
    }

    // Method to perform the left rotation corresponding to the given node - O(1) & O(1)
    Node* leftRotation(Node* rootNode) {
        Node* child = rootNode->right;
        Node* childLeft = child->left;

        child->left = rootNode;
        rootNode->right = childLeft;

        // Update the heights
        rootNode->height = 1 + max(getHeight(rootNode->left), getHeight(rootNode->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right));

        // Return the updated root node
        return child;
    }

    // Method to perform the right rotation corresponding to the given node - O(1) & O(1)
    Node* rightRotation(Node* rootNode) {
        Node* child = rootNode->left;
        Node* childRight = child->right;

        child->right = rootNode;
        rootNode->left = childRight;

        // Update the heights
        rootNode->height = 1 + max(getHeight(rootNode->left), getHeight(rootNode->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right));

        // Return the updated root node
        return child;
    }

public:
    // Method to insert a node in the AVL tree - O(LogN) & O(LogN) : Where N is the total number of nodes of the tree.
    Node* insertToAVL(Node* rootNode, int key) {
        // Edge case: If the tree is empty, then create a new node with value "key" and then return it
        if(!rootNode)
            return new Node(key);

        // If key is lesser, then insert it to the left side of the node
        if(key < rootNode->data) {
            rootNode->left = insertToAVL(rootNode->left, key);
        }
        // If key is greater, then insert it to the right side of the node
        else if(key > rootNode->data) {
            rootNode->right = insertToAVL(rootNode->right, key);
        }
        // Duplicate insertion is not allowed because the AVL tree follows the BST property 
        else {
            return rootNode;
        }

        // 1. Update the height of the node
        rootNode->height = 1 + max(getHeight(rootNode->left), getHeight(rootNode->right));

        // 2. Find the balance factor of the node
        int BF = getHeight(rootNode->left) - getHeight(rootNode->right);

        // Cases of unbalancing:
        // LL Case
        if(BF > 1 && rootNode->left->data > key) {
            return rightRotation(rootNode);
        }
        // LR Case
        else if(BF > 1 && rootNode->left->data < key) {
            rootNode->left = leftRotation(rootNode->left);
            return rightRotation(rootNode);
        }
        // RR Case
        else if(BF < -1 && rootNode->right->data < key) {
            return leftRotation(rootNode);
        }
        // RL Case
        else if(BF < -1 && rootNode->right->data > key) {
            rootNode->right = rightRotation(rootNode->right);
            return leftRotation(rootNode);
        }

        // Already balanced
        return rootNode;
    }
};
