#include<iostream>
#include<string>
using namespace std;

#define MAX 100 

// Reusing the character stack logic
class Stack{
    int top;
    char arr[MAX];

public:
    Stack(){
        top=-1;
    }

    void push(char x){
        if(top==MAX-1){
            cout<<"Stack Overflow!"<<endl;
        }
        else{
            top++;
            arr[top]=x;
        }
    }

    char pop(){
        if(top==-1){
            return '\0';
        }
        else{
            char val = arr[top];
            top--;
            return val;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

int main(){
    string expr;
    cout<<"Enter an expression: ";
    getline(cin, expr); // Reusing the getline fix so spaces don't break it

    Stack s;
    bool isBalanced=true;

    for(int i=0; i<expr.length(); i++){
        char ch = expr[i];

        // Push opening brackets onto the stack
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        // Check closing brackets against the top of the stack
        else if(ch==')' || ch=='}' || ch==']'){
            if(s.isEmpty()){
                isBalanced=false;
                break;
            }
            
            char topChar = s.pop();
            
            // Check for mismatched bracket pairs
            if((ch==')' && topChar!='(') || 
               (ch=='}' && topChar!='{') || 
               (ch==']' && topChar!='[')){
                isBalanced=false;
                break;
            }
        }
    }

    // If the loop finishes but the stack still has opening brackets left
    if(!s.isEmpty()){
        isBalanced=false;
    }

    if(isBalanced){
        cout<<"The expression is balanced."<<endl;
    }
    else{
        cout<<"The expression is NOT balanced."<<endl;
    }

    return 0;
}