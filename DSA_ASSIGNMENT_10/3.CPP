
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

    cout << "Frequencies:\n";

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] != 0) {
            cout << arr[i] << " -> "
                 << freq[arr[i]] << " times" << endl;

            freq[arr[i]] = 0;
        }
    }

    return 0;
}