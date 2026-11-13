//4. Write a program to determine whether a given binary tree is a BST or not. 


#include <iostream>
#include <climits>
using namespace std;

// Structure of Binary Tree Node
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

// Check whether Binary Tree is BST
bool isBST(Node* root, long long minValue, long long maxValue) {

    if (root == NULL)
        return true;

    if (root->data <= minValue || root->data >= maxValue)
        return false;

    return isBST(root->left, minValue, root->data) &&
           isBST(root->right, root->data, maxValue);
}

// Main Function
int main() {

    // Creating a Binary Tree
    Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    // Checking BST
    if (isBST(root, LLONG_MIN, LLONG_MAX))
        cout << "The given Binary Tree is a BST.";
    else
        cout << "The given Binary Tree is NOT a BST.";

    return 0;
}
