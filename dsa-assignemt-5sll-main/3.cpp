#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* head=NULL;
    Node* temp = NULL;

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter elements: ";

    for(int i=0; i<n; i++){
        int x;
        cin>> x;

        Node* newNode = new Node;
        newNode->data=x;
        newNode->next=NULL;

        if(head == NULL)
            head=newNode;
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }

    Node* slow=head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
    }
    
    cout<<"Middle element: "<<slow->data;

    return 0;
}