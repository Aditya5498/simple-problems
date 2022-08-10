#include<iostream>
using namespace std;

// Structure of a Node in Linked List
struct Node{
int val;
Node *next;

Node(int Val){
val=Val;
next=NULL;
}

Node(int val,Node *next){
    val=val;
    next=next;
}
};

// Inserting a head to the linked list
Node* insertHead(Node *head,Node *node){
    node->next=head;
    head=node;
    return node;
}

//Inserting a new node in between the linked list
void insert(Node *prevNode, Node *newNode){
Node *temp=prevNode->next;
prevNode->next=newNode;
newNode->next=temp;
}

//Inserting a new tail in the lined list
void insert(Node *head,int num){
    while(head->next) head=head->next;
    head->next=new Node(num);
}

//find middle node 
void findMiddle(Node *head){
Node *slow=head;
Node *fast=head;
while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
}
cout<<"The middle element is "<<slow->val<<endl;
}

//Deleting a node O(N);
bool deleteNode(Node *head, Node *ptr){
    if(ptr){
        Node *temp=head;
        while(temp->next!=ptr) temp=temp->next;
        temp->next=ptr->next;
        delete ptr;
        return true;
    }
    return false;
}

//Printing the linked list
void printList(Node *head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<" -> ";
        head=head->next;
    }
    cout<<endl;
}

//Reverse the linked list
Node* reverseLinkedList(Node *head){
Node *prev=nullptr;
Node *present=head;
Node *next=head->next;

while(next){
    present->next=prev;
    prev=present;
    present=next;   
    next=next->next;
}
present->next=prev;

return present;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    findMiddle(head);
    printList(head);
    head=insertHead(head,new Node(10));
    findMiddle(head);
    printList(head);
    insert(head,19);
    printList(head);
    insert(head->next->next,new Node(23));
    printList(head);
    deleteNode(head,head->next);
    findMiddle(head);
    printList(head);
    head=reverseLinkedList(head);
    printList(head);
    return 0;
}

