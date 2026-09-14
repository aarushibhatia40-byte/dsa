#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>> n;

    
    int A[100]; 
    
    cout<<"Enter elements of array:"<<endl;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    int invCount=0;

    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j]){
                invCount++;
            }
        }
    }

    cout<<"Total number of inversions: "<< invCount<<endl;

    return 0;
}