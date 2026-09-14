#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[100];
    
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    int duplicate;

    for(int i=0; i<n; i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                duplicate = arr[i];
                break;
            }
        }
    }
    
    cout<<"Duplicate number: "<< duplicate;

    return 0;
}