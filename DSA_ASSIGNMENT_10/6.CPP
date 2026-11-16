
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

bool checkDuplicate(Node* root, unordered_set<int>& s) {
    if (root == NULL)
        return false;

    if (s.find(root->data) != s.end())
        return true;

    s.insert(root->data);

    return checkDuplicate(root->left, s) ||
           checkDuplicate(root->right, s);
}

int main() {
    Node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(20);

    unordered_set<int> s;

    if (checkDuplicate(root, s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}