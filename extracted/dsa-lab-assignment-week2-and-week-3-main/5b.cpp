#include<iostream>
using namespace std;

class Tridiagonal{
    int *A;
    int n;

public:
    Tridiagonal(int size){
        n = size;
        A = new int[3*n - 2];
    }

    void set(int i,int j,int x){
        if(i - j == 1){ 
            A[i - 2] = x;
        }
        else if(i - j == 0){ 
            A[n + i - 2] = x;
        }
        else if(i - j == -1){ 
            A[2*n + i - 2] = x;
        }
    }

    int get(int i,int j){
        if(i - j == 1){
            return A[i - 2];
        }
        else if(i - j == 0){
            return A[n + i - 2];
        }
        else if(i - j == -1){
            return A[2*n + i - 2];
        }
        return 0;
    }

    void display(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i - j == 1){
                    cout<<A[i - 2]<<" ";
                }
                else if(i - j == 0){
                    cout<<A[n + i - 2]<<" ";
                }
                else if(i - j == -1){
                    cout<<A[2*n + i - 2]<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }

    ~Tridiagonal(){
        delete [] A;
    }
};

int main(){
    int n;
    cout<<"Enter dimension of matrix: ";
    cin>> n;

    Tridiagonal t(n);

    cout<<"Enter elements row-wise:"<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin>>x;
            t.set(i, j, x);
        }
    }

    cout<<"\nEfficiently Stored Tri-diagonal Matrix:"<<endl;
    t.display();

    return 0;
}