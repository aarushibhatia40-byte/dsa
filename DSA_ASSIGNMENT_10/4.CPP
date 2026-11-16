
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, arr[100];

    cout << "Enter size: ";
    cin >> n;

    unordered_map<int, int> freq;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 1) {
            cout << "First Non-Repeating Element: "
                 << arr[i];
            return 0;
        }
    }

    cout << "No Non-Repeating Element";

    return 0;
}