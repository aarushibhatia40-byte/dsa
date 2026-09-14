#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MAX 100 


class Stack{
    int top;
    int arr[MAX];

public:
    Stack(){
        top=-1;
    }

    void push(int x){
        if(top<MAX-1){
            top++;
            arr[top]=x;
        }
        else{
            cout<<"Stack Overflow!"<<endl;
        }
    }

    int pop(){
        if(top==-1){
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }
};

int main(){
    string postfix;
    cout<<"Enter Postfix expression (single digit operands): ";
    getline(cin, postfix); 

    Stack s;

    for(int i=0; i<postfix.length(); i++){
        char ch = postfix[i];

      
        if(ch==' '){
            continue;
        }
     
        else if(ch>='0' && ch<='9'){
            s.push(ch-'0'); 
        }
       
        else{
            int val1 = s.pop(); 
            int val2 = s.pop(); 

            switch(ch){
                case '+': s.push(val2+val1); break;
                case '-': s.push(val2-val1); break;
                case '*': s.push(val2*val1); break;
                case '/': s.push(val2/val1); break;
                case '^': s.push(pow(val2,val1)); break;
            }
        }
    }

    cout<<"Evaluated Result: "<< s.pop()<<endl;

    return 0;
}