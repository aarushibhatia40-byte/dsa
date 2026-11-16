
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

bool detectLoop(Node* head) {
    unordered_set<Node*> s;

    Node* temp = head;

    while (temp != NULL) {
        if (s.find(temp) != s.end())
            return true;

        s.insert(temp);
        temp = temp->next;
    }

    return false;
}

int main() {
    Node* head = createNode(1);

    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Create loop: 4 points back to 2
    head->next->next->next->next = head->next;

    if (detectLoop(head))
        cout << "Loop Found";
    else
        cout << "No Loop";

    return 0;
}