#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter rows and columns: ";
    cin>>n>> m;

    int a[10][10];
    
    cout<<"Enter matrix elements: ";
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Zigzag diagonal order: ";

    for(int d=0; d<n+m-1; d++){

        if(d%2 == 0){
            int i = d;
            if(i>=n)
                i=n-1;

            int j=d-i;

            while(i>=0 && j<m){
                cout<<a[i][j]<<" ";
                i--;
                j++;
            }
        }
        else{
            int j=d;
            if(j>=m)
                j = m-1;

            int i=d-j;

            while(j>=0 && i<n){
                cout<<a[i][j]<<" ";
                i++;
                j--;
            }
        }
    }
    
    return 0;
}