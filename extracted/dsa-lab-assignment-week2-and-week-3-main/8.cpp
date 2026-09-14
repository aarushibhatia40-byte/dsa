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

    int distinctCount=0;

 
    for(int i=0; i<n; i++){
        bool isDuplicate=false;
        
        for(int j=0; j<i; j++){
            if(A[i]==A[j]){
                isDuplicate=true;
                break;
            }
        }
        
        if(!isDuplicate){
            distinctCount++;
        }
    }

    cout<<"Total distinct elements: "<< distinctCount<<endl;

    return 0;
}