#include<iostream>
using namespace std;
 
class node{
 
    public:
    int data;
    node* next;
 
    node(int val){
        data=val;
        next=NULL;
    }
};
 
void insertAtHead(node* &head, int val){
    node* n=new node(val);
 
    if(head==NULL){ //if list is empty
        n->next=n; //the only node's next pointer will point to itself
        head=n; //head is assigned to the only node
        return;
    }
    //else
    node* temp=head; //temp node to traverse list
 
    while(temp->next!=head){ //last node's next is head, so traverse to last node
        temp=temp->next;
    }
    temp->next=n; //last's node next node is new node
    n->next=head; //new node's next node is previous head
    head=n; // head is reassigned to new node
}
 
void insertAtTail(node* &head, int val){
 
    if(head==NULL){ //if list is empty
        insertAtHead(head,val); 
        return;
    }
   //else
    node* n = new node(val); //create new node
    node* temp=head; //temp node for traversal
 
    while(temp->next!=head){ //traverse to the last node
        temp=temp->next; 
    }
 
    temp->next=n; //last node's next is assigned to new node
    n->next=head; // new node's next is assigned to head
}
 
void deleteAtHead(node* &head){
    node* temp=head; //create temp node for traversal
    while(temp->next!=head){ //traverse to the last node
        temp=temp->next;
    }
 
    node* todelete=head; //set todelete node as head
    temp->next=head->next; //set last node next to head's next
    head=head->next; //reassign head to head's next
 
    delete todelete; //delete previous head
}
 
void deletion(node* &head, int pos){
 
    if(pos==1){ //1st position= head
        deleteAtHead(head);
        return;
    }
    //else
      node* temp=head; //create temp node for traversal
      int count=1; 
 
      while(count!=pos-1){ //traverse to the previous node to be deleted
          temp=temp->next;
          count++;
      }
 
      node* todelete=temp->next; // assign to delete 
      temp->next=temp->next->next; //assign to delete's previous node next to todelete next node
 
      delete todelete; //delete to detele
}
 
void display(node* head){
 
 
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
}
 
 
int main(){
 
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,1);
    display(head);
    
 
    return 0;
}