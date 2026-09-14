#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int val){
    Node* newNode = new Node();
    newNode->data=val;
    newNode->next=head;
    head = newNode;
}

void insertEnd(int val){
    Node* newNode=new Node();
    newNode->data = val;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void insertBetween(){
    int val,target,choice;
    cout<<"Enter value to insert: ";
    cin>> val;
    cout<<"Enter target node value: ";
    cin>>target;
    cout<<"1. Insert Before  2. Insert After\nChoice: ";
    cin>>choice;

    Node* newNode=new Node();
    newNode->data=val;

    if(head == NULL){
        cout<<"List is empty!\n";
        return; 
    }

    if(choice==1){
        if(head->data==target){
            newNode->next=head;
            head = newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL && temp->next->data!=target){
            temp=temp->next;
        }
        if(temp->next==NULL)
            cout<<"Node not found\n";
        else{
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    else if(choice==2){
        Node* temp=head;
        while(temp!=NULL && temp->data!=target){
            temp=temp->next;
        }
        if(temp==NULL)
            cout<<"Node not found\n";
        else{
            newNode->next = temp->next;
            temp->next=newNode;
        }
    }
}

void deleteBegin(){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}

void deleteEnd(){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    if(head->next == NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int val){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    if(head->data==val){
        Node* temp = head;
        head=head->next;
        delete temp;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL && temp->next->data!=val){
        temp=temp->next;
    }
    
    if(temp->next==NULL){
        cout<<"Node not found\n";
    }
    else{
        Node* del = temp->next;
        temp->next=temp->next->next;
        delete del;
    }
}

void searchNode(int val){
    Node* temp=head;
    int pos=1;
    while(temp!=NULL){
        if(temp->data == val){
            cout<<"Found at position "<<pos<<endl;
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout<<"Not found in list\n";
}

void display(){
    if(head==NULL){
        cout<<"List empty\n";
        return;
    }
    Node* temp=head;
    cout<<"List: ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    int ch,val;
    
    while(1){
        cout<<"\n--- LINKED LIST MENU ---\n";
        cout<<"1. Insert Begin\n2. Insert End\n3. Insert Between\n4. Delete Begin\n5. Delete End\n6. Delete Specific Node\n7. Search\n8. Display\n9. Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"Enter value: ";
                cin>> val;
                insertBegin(val);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>val;
                insertEnd(val);
                break;
            case 3:
                insertBetween();
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteSpecific(val);
                break;
            case 7:
                cout<<"Enter value to search: ";
                cin>>val;
                searchNode(val);
                break;
            case 8:
                display();
                break;
            case 9:
                return 0;
            default:
                cout<<"Invalid choice\n";
        }
    }
}