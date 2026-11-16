
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    int a[100];

    unordered_set<int> s, printed;

    cout << "Enter first array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    cout << "Enter size of second array: ";
    cin >> m;

    int b[100];

    cout << "Enter second array: ";
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << "Common Elements: ";

    for (int i = 0; i < m; i++) {
        if (s.find(b[i]) != s.end() &&
            printed.find(b[i]) == printed.end()) {

            cout << b[i] << " ";
            printed.insert(b[i]);
        }
    }

    return 0;
}