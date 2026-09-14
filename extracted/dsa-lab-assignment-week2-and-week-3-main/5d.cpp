#include<iostream>
using namespace std;

class UpperTriangular{
    int *A;
    int n;

public:
    UpperTriangular(int size){
        n = size;
        A = new int[n*(n+1)/2];
    }

    void set(int i,int j,int x){
        if(i<=j){
            int index = n*(i-1) - (i-2)*(i-1)/2 + (j-i);
            A[index]=x;
        }
    }

    int get(int i,int j){
        if(i<=j){
            return A[n*(i-1) - (i-2)*(i-1)/2 + (j-i)];
        }
        return 0;
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i<=j){
                    cout<<A[n*(i-1) - (i-2)*(i-1)/2 + (j-i)]<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }

    ~UpperTriangular(){
        delete [] A;
    }
};

int main(){
    int n;
    cout<<"Enter dimension of matrix: ";
    cin>> n;

    UpperTriangular um(n);

    cout<<"Enter elements row-wise:"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            um.set(i,j,x);
        }
    }

    cout<<"\nEfficiently Stored Upper Triangular Matrix:"<<endl;
    um.display();

    return 0;
}