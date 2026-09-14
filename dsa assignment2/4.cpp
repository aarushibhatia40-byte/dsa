#include <iostream>
using namespace std;

int main(){
    int r1,c1,r2,c2;
    cout<<"Enter rows and columns of first matrix: ";
    cin>>r1>>c1;

    cout<<"Enter rows and columns of second matrix: ";
    cin>> r2>>c2;

    if(c1!=r2){
        cout<<"Matrix multiplication not possible";
        return 0;
    }

    int a[50][3],b[50][3], c[100][3];
    int n1=0,n2=0, n3=0;

    cout<<"Enter first sparse matrix: ";
    for(int i=0; i<r1; i++){
        for(int j=0;j<c1;j++){
            int x;
            cin>>x;
            if(x!=0){
                a[n1][0]=i;
                a[n1][1]=j;
                a[n1][2] = x;
                n1++;
            }
        }
    }

    cout<<"Enter second sparse matrix: ";
    for(int i=0;i<r2;i++){
        for(int j=0; j<c2; j++){
            int x;
            cin>> x;
            if(x != 0){
                b[n2][0] = i;
                b[n2][1] = j;
                b[n2][2]=x;
                n2++;
            }
        }
    }
    
    for(int i=0; i<n1; i++){
        for(int j=0;j<n2;j++){
            if(a[i][1] == b[j][0]){
                int row = a[i][0];
                int col = b[j][1];
                int value = a[i][2] * b[j][2];

                int k;
                for(k=0; k<n3; k++){
                    if(c[k][0]==row && c[k][1]==col){
                        c[k][2] += value;
                        break;
                    }
                }

                if(k==n3){
                    c[n3][0]=row;
                    c[n3][1]=col;
                    c[n3][2] = value;
                    n3++;
                }
            }
        }
    }

    cout<<"Result in sparse form:"<< endl;
    cout<<"Row Column Value"<<endl;

    for(int i=0;i<n3;i++){
        cout<<c[i][0]<<"    "<<c[i][1]<<"     "<<c[i][2]<<endl;
    }

    return 0;
}