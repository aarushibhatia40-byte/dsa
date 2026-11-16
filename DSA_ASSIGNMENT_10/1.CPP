
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];
    unordered_set<int> s;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (s.find(arr[i]) != s.end()) {
            cout << "Duplicates Found";
            return 0;
        }

        s.insert(arr[i]);
    }

    cout << "No Duplicates";

    return 0;
}