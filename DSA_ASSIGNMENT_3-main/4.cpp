#include<iostream>
#include<string>
using namespace std;

#define MAX 100 

// Reusing the character stack 
class Stack{
    int top;
    char arr[MAX];

public:
    Stack(){
        top=-1;
    }

    void push(char x){
        if(top<MAX-1){
            top++;
            arr[top]=x;
        }
        else{
            cout<<"Stack Overflow!"<<endl;
        }
    }

    char pop(){
        if(top==-1){
            return '\0';
        }
        char val = arr[top];
        top--;
        return val;
    }

    char peek(){
        if(top==-1){
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};


int precedence(char op){
    if(op=='^'){
        return 3;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    else if(op=='+' || op=='-'){
        return 1;
    }
    return -1;
}

int main(){
    string infix;
    cout<<"Enter Infix expression: ";
    getline(cin, infix); 

    Stack s;
    string postfix="";

    for(int i=0; i<infix.length(); i++){
        char ch = infix[i];

        
        if(ch==' '){
            continue;
        }
      
        else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            postfix += ch;
        }
     
        else if(ch=='('){
            s.push(ch);
        }
       
        else if(ch==')'){
            while(!s.isEmpty() && s.peek()!='('){
                postfix += s.pop();
            }
            s.pop(); 
        }
       
        else{
            while(!s.isEmpty() && precedence(s.peek())>=precedence(ch)){
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

   
    while(!s.isEmpty()){
        postfix += s.pop();
    }

    cout<<"Postfix expression: "<< postfix<<endl;

    return 0;
}