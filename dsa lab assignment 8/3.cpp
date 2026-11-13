// 3. Write a program for binary search tree (BST) having functions for the following 
// operations: 
// (a) Insert an element (no duplicates are allowed), 
// (b) Delete an existing element, 
// (c) Maximum depth of BST 
// (d) Minimum depth of  


#include <iostream>
#include <algorithm>
using namespace std;

// Structure of BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// (a) Insert an element (No duplicates)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        cout << "\nDuplicate value not allowed: " << value;

    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// (b) Delete an existing element
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// (c) Maximum Depth of BST
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left),
                   maxDepth(root->right));
}

// (d) Minimum Depth of BST
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left),
                   minDepth(root->right));
}

// Display BST in In-order
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main Function
int main() {
    Node* root = NULL;

    // Inserting elements
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "\nBST In-order: ";
    inorder(root);

    // Deleting an element
    root = deleteNode(root, 30);

    cout << "\nAfter Deletion: ";
    inorder(root);

    // Maximum Depth
    cout << "\nMaximum Depth: " << maxDepth(root);

    // Minimum Depth
    cout << "\nMinimum Depth: " << minDepth(root);

    return 0;
}
