#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* head=NULL;
    Node* temp;
    int n, key;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter elements: ";

    for(int i=0; i<n; i++){
        int x;
        cin>> x;

        Node* newNode = new Node;
        newNode->data=x;
        newNode->next=NULL;

        if(head == NULL){
            head=newNode;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }

    cout<<"Enter key: ";
    cin>>key;

    int count=0;

    while(head!=NULL && head->data == key){
        temp=head;
        head=head->next;
        delete temp;
        count++;
    }

    temp=head;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->data==key){
            Node* del = temp->next;
            temp->next=del->next;
            delete del;
            count++;
        }
        else{
            temp=temp->next;
        }
    }
    
    cout<<"Count: "<< count <<endl;

    cout<<"Updated Linked List: ";
    temp=head;

    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL)
            cout<<"->";
            
        temp=temp->next;
    }

    return 0;
}