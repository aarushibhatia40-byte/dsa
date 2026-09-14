#include<iostream>
#include<string>
using namespace std;

#define MAX 100 

// Custom stack specifically for characters
class CharStack{
    int top;
    char arr[MAX];

public:
    CharStack(){
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
    string str;
    cout<<"Enter a string: ";
    
    // Safely reads the entire line even if it contains spaces
    getline(cin, str);

    CharStack s;

    // Step 1: Push all characters of the string into the stack
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    string reversedStr = "";

    // Step 2: Pop characters until empty (LIFO automatically reverses it)
    while(!s.isEmpty()){
        reversedStr += s.pop();
    }

    cout<<"Reversed string: "<< reversedStr<<endl;

    return 0;
}