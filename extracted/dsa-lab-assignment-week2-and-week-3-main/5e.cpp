#include<iostream>
using namespace std;

class Symmetric{
    int *A;
    int n;

public:
    Symmetric(int size){
        n = size;
        A = new int[n*(n+1)/2];
    }

    void set(int i,int j,int x){
        if(i>=j){
            int index = i*(i-1)/2 + (j-1);
            A[index]=x;
        }
        else{
            int index = j*(j-1)/2 + (i-1);
            A[index]=x;
        }
    }

    int get(int i,int j){
        if(i>=j){
            return A[i*(i-1)/2 + (j-1)];
        }
        else{
            return A[j*(j-1)/2 + (i-1)];
        }
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i>=j){
                    cout<<A[i*(i-1)/2 + (j-1)]<<" ";
                }
                else{
                    cout<<A[j*(j-1)/2 + (i-1)]<<" ";
                }
            }
            cout<<endl;
        }
    }

    ~Symmetric(){
        delete [] A;
    }
};

int main(){
    int n;
    cout<<"Enter dimension of matrix: ";
    cin>> n;

    Symmetric sm(n);

    cout<<"Enter elements row-wise:"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            sm.set(i,j,x);
        }
    }

    cout<<"\nEfficiently Stored Symmetric Matrix:"<<endl;
    sm.display();

    return 0;
}