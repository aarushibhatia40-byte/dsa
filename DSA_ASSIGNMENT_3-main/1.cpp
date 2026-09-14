#include<iostream>
using namespace std;

#define MAX 100 

class Stack{
    int top;
    int arr[MAX];

public:
    // Constructor
    Stack(){
        top=-1;
    }

    // (iv) isFull
    bool isFull(){
        if(top==MAX-1){
            return true;
        }
        return false;
    }

    // (iii) isEmpty
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    // (i) push
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow!"<<endl;
        }
        else{
            top++;
            arr[top]=x;
            cout<<x<<" pushed to stack."<<endl;
        }
    }

    // (ii) pop
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow!"<<endl;
        }
        else{
            cout<<"Popped element: "<< arr[top]<<endl;
            top--;
        }
    }

    // (vi) peek
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
        }
        else{
            cout<<"Top element is: "<< arr[top]<<endl;
        }
    }

    // (v) display
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
        }
        else{
            cout<<"Stack elements: ";
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Stack s;
    char choice; 
    int val;

    while(true){
        cout<<"\n--- Stack Menu ---"<<endl;
        cout<<"1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout<<"Enter your choice: ";
        cin>> choice;

        switch(choice){
            case '1':
                cout<<"Enter value to push: ";
                cin>>val;
                // Protection for the value input 
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout<<"Invalid value! Push cancelled."<<endl;
                    break;
                }
                s.push(val);
                break;
            case '2':
                s.pop();
                break;
            case '3':
                if(s.isEmpty()){
                    cout<<"Stack is empty.\n";
                }
                else{
                    cout<<"Stack is not empty.\n";
                }
                break;
            case '4':
                if(s.isFull()){
                    cout<<"Stack is full.\n";
                }
                else{
                    cout<<"Stack is not full.\n";
                }
                break;
            case '5':
                s.display();
                break;
            case '6':
                s.peek();
                break;
            case '7':
                cout<<"Exiting..."<<endl;
                return 0; 
            default:
                cout<<"Invalid choice! Try again."<<endl;
        }
    }

    return 0;
}