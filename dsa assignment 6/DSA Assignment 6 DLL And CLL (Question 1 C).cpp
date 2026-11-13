#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    // Search for the node to delete
    do {
        if (current->data == value) {
            break;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    // Node not found
    if (current->data != value) {
        cout << "Node " << value << " not found." << endl;
        return;
    }

    // If there is only one node
    if (current == head && head->next == head) {
        delete head;
        head = NULL;
    }

    // If the node to delete is the head node
    else if (current == head) {
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        delete current;
    }

    // If the node is in between or the last node
    else {
        previous->next = current->next;
        delete current;
    }

    cout << "Node " << value << " deleted successfully." << endl;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(60);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    int value;

    cout << "Original Circular Linked List: ";
    display(head);

    cout << "Enter the node value to delete: ";
    cin >> value;

    deleteNode(head, value);

    cout << "Updated Circular Linked List: ";
    display(head);

    return 0;
}