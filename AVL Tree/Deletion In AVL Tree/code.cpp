class Node {
public:
    int data, height;
    Node *left, *right;

    Node(int x) {
	data = x;
	height = 1;
	left = right = nullptr;
    }
};

class AVLTreeDeletion {
    // O(1) & O(1)
    int getHeight(Node* rootNode) {
        if(!rootNode)
            return 0;

        return rootNode->height;
    }

    // O(1) & O(1)
    int getBalanceFactor(Node* rootNode) {
        if(!rootNode)
            return 0;

        return getHeight(rootNode->left) - getHeight(rootNode->right);
    }

    // O(1) & O(1)
    Node* rotateLeft(Node* rootNode) {
        Node* child = rootNode->right;
        rootNode->right = child->left;
        child->left = rootNode;

        rootNode->height = 1 + max(getHeight(rootNode->left), getHeight(rootNode->right));
        child->height    = 1 + max(getHeight(child->left), getHeight(child->right));

        return child;
    }

    // O(1) & O(1)
    Node* rotateRight(Node* rootNode) {
        Node* child = rootNode->left;
        rootNode->left = child->right;
        child->right = rootNode;

        rootNode->height = 1 + max(getHeight(rootNode->left), getHeight(rootNode->right));
        child->height    = 1 + max(getHeight(child->left), getHeight(child->right));

        return child;
    }

    // O(LogN) & O(1)
    int getLeftMostNode(Node* rootNode) {
        while(rootNode->left) {
            rootNode = rootNode->left;
        }
        return rootNode->data;
    }

public:
    // Method to delete a node from the AVL Tree - O(LogN) & O(LogN)
    Node* deleteNode(Node* rootNode, int key) {
        // Edge case: If the tree is empty, then key doesn't exist
        if(!rootNode)
            return nullptr;

        // If key is lesser, then search and delete it from the left side of the node
        if(key < rootNode->data) {
            rootNode->left = deleteNode(rootNode->left, key);
        }
        // If key is greater, then search and delete it from the right side of the node
        else if(key > rootNode->data) {
            rootNode->right = deleteNode(rootNode->right, key);
        }
        // At this point the key is found. Case when only left child exists or when its a leaf node 
        else if(!rootNode->right) {
            return rootNode->left;
        }
        // When only right child exist or when both childs exists 
        else {
            int leftMostVal = getLeftMostNode(rootNode->right);
            rootNode->data  = leftMostVal;
            rootNode->right = deleteNode(rootNode->right, leftMostVal);
        }

        // 1. Update the height of the node
        rootNode->height = 1 + max(getHeight(rootNode->left), getHeight(rootNode->right));

        // 2. Find the balance factor of the node
        int BF = getBalanceFactor(rootNode);

        // Cases of unbalancing:
        // LL
        if(BF > 1 && getBalanceFactor(rootNode->left) >= 0) {
            return rotateRight(rootNode);
        }
        // RR
        else if(BF < -1 && getBalanceFactor(rootNode->right) <= 0) {
            return rotateLeft(rootNode);
        }
        // LR
        else if(BF > 1 && getBalanceFactor(rootNode->left) < 0) {
            rootNode->left = rotateLeft(rootNode->left);
            return rotateRight(rootNode);
        }
        // RL
        else if(BF < -1 && getBalanceFactor(rootNode->right) > 0) {
            rootNode->right = rotateRight(rootNode->right);
            return rotateLeft(rootNode);
        }

        // Already balanced
        return rootNode;
    }
};
