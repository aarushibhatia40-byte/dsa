// 2. Implement following functions for Binary Search Trees  
// (a) Search a given item (Recursive & Non-Recursive) 
// (b) Maximum element of the BST  
// (c) Minimum element of the BST  
// (d) In-order successor of a given node the BST  
// (e) In-order predecessor of a given node the BST  


#include <iostream>
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

// Insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// (a) Recursive Search
Node* recursiveSearch(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return recursiveSearch(root->left, key);

    return recursiveSearch(root->right, key);
}

// (a) Non-Recursive Search
Node* iterativeSearch(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Find Maximum Element
Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// (c) Find Minimum Element
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// (d) Find In-order Successor
Node* successor(Node* root, int key) {
    Node* current = recursiveSearch(root, key);

    if (current == NULL)
        return NULL;

    if (current->right != NULL)
        return findMin(current->right);

    Node* succ = NULL;

    while (root != NULL) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else
            break;
    }

    return succ;
}

// (e) Find In-order Predecessor
Node* predecessor(Node* root, int key) {
    Node* current = recursiveSearch(root, key);

    if (current == NULL)
        return NULL;

    if (current->left != NULL)
        return findMax(current->left);

    Node* pred = NULL;

    while (root != NULL) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else
            break;
    }

    return pred;
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

    // Creating BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "BST In-order: ";
    inorder(root);

    int key = 40;

    // Recursive Search
    if (recursiveSearch(root, key) != NULL)
        cout << "\nRecursive Search: Item Found";
    else
        cout << "\nRecursive Search: Item Not Found";

    // Non-Recursive Search
    if (iterativeSearch(root, key) != NULL)
        cout << "\nNon-Recursive Search: Item Found";
    else
        cout << "\nNon-Recursive Search: Item Not Found";

    // Maximum Element
    cout << "\nMaximum Element: " << findMax(root)->data;

    // Minimum Element
    cout << "\nMinimum Element: " << findMin(root)->data;

    // Successor
    Node* succ = successor(root, key);
    if (succ != NULL)
        cout << "\nIn-order Successor of " << key << ": " << succ->data;
    else
        cout << "\nNo Successor";

    // Predecessor
    Node* pred = predecessor(root, key);
    if (pred != NULL)
        cout << "\nIn-order Predecessor of " << key << ": " << pred->data;
    else
        cout << "\nNo Predecessor";

    return 0;
}
