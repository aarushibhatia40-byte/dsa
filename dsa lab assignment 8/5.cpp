// 5. Implement Heapsort (Increasing/Decreasing order).


#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (increasing) {
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
    }
    else {
        if (left < n && arr[left] < arr[largest])
            largest = left;
        if (right < n && arr[right] < arr[largest])
            largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {40, 10, 30, 50, 20};
    int n = 5;

    cout << "Original Array: ";
    display(arr, n);

    int inc[] = {40, 10, 30, 50, 20};
    heapSort(inc, n, true);
    cout << "Increasing Order: ";
    display(inc, n);

    int dec[] = {40, 10, 30, 50, 20};
    heapSort(dec, n, false);
    cout << "Decreasing Order: ";
    display(dec, n);

    return 0;
}
