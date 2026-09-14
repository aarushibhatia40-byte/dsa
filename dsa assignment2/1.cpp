#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin>>n;

    int arr[100];

    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i=0;
    int j=n-1;

    while (i<j){
        int temp= arr[i];
        arr[i]= arr[j];
        arr[j]= temp;
        i++;
        j--;
    }

    cout << "Reversed array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}