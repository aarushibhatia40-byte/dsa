#include<iostream>
using namespace std;

class LowerTriangular{
    int *A;
    int n;

public:
    LowerTriangular(int size){
        n = size;
        A = new int[n*(n+1)/2];
    }

    void set(int i,int j,int x){
        if(i>=j){
            int index = i*(i-1)/2 + (j-1);
            A[index]=x;
        }
    }

    int get(int i,int j){
        if(i>=j){
            return A[i*(i-1)/2 + (j-1)];
        }
        return 0;
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i>=j){
                    cout<<A[i*(i-1)/2 + (j-1)]<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<< endl;
        }
    }

    ~LowerTriangular(){
        delete [] A;
    }
};

int main(){
    int n;
    cout<<"Enter dimension of matrix: ";
    cin>> n;

    LowerTriangular lm(n);

    cout<<"Enter elements row-wise:"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            lm.set(i,j,x);
        }
    }

    cout<<"\nEfficiently Stored Lower Triangular Matrix:"<< endl;
    lm.display();

    return 0;
}