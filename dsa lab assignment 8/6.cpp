//6. Implement priority queues using heaps.

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete Highest Priority Element";
        cout << "\n3. Display Priority Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            pq.push(value);
            cout << "Element inserted.";
            break;

        case 2:
            if (!pq.empty()) {
                cout << "Deleted element: " << pq.top();
                pq.pop();
            } else {
                cout << "Priority Queue is empty.";
            }
            break;

        case 3:
            if (pq.empty()) {
                cout << "Priority Queue is empty.";
            } else {
                priority_queue<int> temp = pq;
                cout << "Priority Queue: ";
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
            }
            break;

        case 4:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice.";
        }
    } while (choice != 4);

    return 0;
}
