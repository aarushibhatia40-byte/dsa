#include<iostream>
using namespace std;

int main(){
    int arr[]={10, 20, 30, 40, 50, 60, 70};
    int n=7;
    int key;

    cout<<"Enter element to search: ";
    cin>> key;

    int low=0;
    int high = n-1;
    bool found=false;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(arr[mid]==key){
            cout<<"Element found at position "<<mid+1<<endl;
            found=true;
            break;
        }
        else if(key<arr[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    if(!found){
        cout<<"Element not found"<< endl;
    }

    return 0;
}