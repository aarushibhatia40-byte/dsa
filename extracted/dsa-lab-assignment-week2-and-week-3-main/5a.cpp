#include<iostream>
using namespace std;

class Diagonal{
    int *A;
    int n;

public:
    Diagonal(int size){
        n = size;
        A = new int[n];
    }

    void set(int i,int j,int x){
        if(i==j){
            A[i-1]=x;
        }
    }

    int get(int i,int j){
        if(i==j){
            return A[i-1];
        }
        return 0;
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j){
                    cout<<A[i-1]<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }

    ~Diagonal(){
        delete [] A;
    }
};

int main(){
    int n;
    cout<<"Enter dimension of matrix: ";
    cin>> n;

    Diagonal d(n);

    cout<<"Enter elements row-wise:"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            d.set(i,j,x);
        }
    }

    cout<<"\nEfficiently Stored Diagonal Matrix:"<< endl;
    d.display();

    return 0;
}