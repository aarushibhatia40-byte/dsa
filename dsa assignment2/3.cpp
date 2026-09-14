#include <iostream>
using namespace std;

int main(){
    int rows,cols;
    cout<<"Enter number of rows and columns: ";
    cin>>rows>>cols;

    int matrix[10][10];
    
    cout<<"Enter matrix elements: ";
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Transpose of sparse matrix:"<< endl;

    for(int j=0; j<cols; j++){
        for(int i=0;i<rows;i++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}