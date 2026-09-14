#include<iostream>
using namespace std;


struct Element{
    int row;
    int col;
    int val;
};

class SparseMatrix{
    int m;
    int n;
    int num;
    Element e[100]; 

public:
    SparseMatrix(int r=0,int c=0,int nzt=0){
        m=r;
        n=c;
        num=nzt;
    }

    void read(){
        cout<<"Enter elements (row, col, value):"<<endl;
        for(int i=0; i<num; i++){
            cin>>e[i].row>>e[i].col>>e[i].val;
        }
    }

    void display(){
        cout<<"Row\tCol\tValue"<<endl;
        for(int i=0; i<num; i++){
            cout<<e[i].row<<"\t"<<e[i].col<<"\t"<<e[i].val<<endl;
        }
    }

    // (a) Transpose of Matrix
    SparseMatrix transpose(){
        SparseMatrix t(n, m, num);
        if(num > 0){
            int k = 0;
           
            for(int c=0; c<n; c++){
                for(int i=0; i<num; i++){
                    if(e[i].col == c){
                        t.e[k].row = e[i].col;
                        t.e[k].col = e[i].row;
                        t.e[k].val = e[i].val;
                        k++;
                    }
                }
            }
        }
        return t;
    }

    // (b) Addition of Matrices
    SparseMatrix add(SparseMatrix b){
        if(m != b.m || n != b.n){
            cout<<"Dimensions don't match for addition!"<<endl;
            return SparseMatrix(0,0,0);
        }

        SparseMatrix sum(m, n, 0);
        int i=0, j=0, k=0;

        // Merge logic
        while(i<num && j<b.num){
            if(e[i].row < b.e[j].row){
                sum.e[k++] = e[i++];
            }
            else if(e[i].row > b.e[j].row){
                sum.e[k++] = b.e[j++];
            }
            else{ // Rows are equal
                if(e[i].col < b.e[j].col){
                    sum.e[k++] = e[i++];
                }
                else if(e[i].col > b.e[j].col){
                    sum.e[k++] = b.e[j++];
                }
                else{ // Rows and Cols are equal
                    sum.e[k] = e[i];
                    sum.e[k++].val = e[i++].val + b.e[j++].val;
                }
            }
        }
        // Copy remaining elements
        while(i<num) sum.e[k++] = e[i++];
        while(j<b.num) sum.e[k++] = b.e[j++];
        
        sum.num = k;
        return sum;
    }

    // (c) Multiplication of Matrices
    SparseMatrix multiply(SparseMatrix b){
        if(n != b.m){
            cout<<"Dimensions don't match for multiplication!"<<endl;
            return SparseMatrix(0,0,0);
        }

        SparseMatrix res(m, b.n, 0);
        // Transpose b to make it easier to compare rows of A with cols of B
        SparseMatrix b_t = b.transpose();
        int k=0;

        for(int i=0; i<num; ){
            int r = e[i].row;
            for(int j=0; j<b_t.num; ){
                int c = b_t.e[j].row; // This is actually the column of original b
                
                int tempA = i;
                int tempB = j;
                int sum = 0;
                
                // Multiply matching elements
                while(tempA < num && e[tempA].row == r && tempB < b_t.num && b_t.e[tempB].row == c){
                    if(e[tempA].col < b_t.e[tempB].col) tempA++;
                    else if(e[tempA].col > b_t.e[tempB].col) tempB++;
                    else{
                        sum += e[tempA].val * b_t.e[tempB].val;
                        tempA++; 
                        tempB++;
                    }
                }
                if(sum != 0){
                    res.e[k].row = r;
                    res.e[k].col = c;
                    res.e[k].val = sum;
                    k++;
                }
                while(j<b_t.num && b_t.e[j].row == c) j++; // Move to next col of b
            }
            while(i<num && e[i].row == r) i++; // Move to next row of a
        }
        res.num = k;
        return res;
    }
};

int main(){
    int r1, c1, n1;
    cout<<"Enter rows, cols, and non-zero terms for Matrix 1: ";
    cin>>r1>>c1>>n1;
    SparseMatrix m1(r1,c1,n1);
    m1.read();

    int r2, c2, n2;
    cout<<"\Enter rows, cols, and non-zero terms for Matrix 2: ";
    cin>>r2>>c2>>n2;
    SparseMatrix m2(r2,c2,n2);
    m2.read();

    cout<<"\n--- Matrix 1 ---"<<endl;
    m1.display();

    cout<<"\n--- Matrix 1 Transpose ---"<<endl;
    SparseMatrix trans = m1.transpose();
    trans.display();

    cout<<"\n--- Matrix 1 + Matrix 2 ---"<<endl;
    SparseMatrix added = m1.add(m2);
    added.display();

    cout<<"\n--- Matrix 1 * Matrix 2 ---"<<endl;
    SparseMatrix mult = m1.multiply(m2);
    mult.display();

    return 0;
}