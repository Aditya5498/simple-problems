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
    if(!head) cout<<"NULL node\n";
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

// Reverses the linked list in groups
// of size k and returns the pointer
// to the new head node.
//function to reverse every k nodes -> https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

Node* reverseKnodes(Node *head,int k){
// base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
  
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
  
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverseKnodes(next, k);
  
    /* prev is new head of the input list */
    return prev;
}

/* Reverses alternate k nodes and 
returns the pointer to the new head node */
Node *kAltReverse(Node *head, int k) 
{ 
    Node* current = head; 
    Node* next; 
    Node* prev = NULL; 
    int count = 0; 
  
    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k) 
    { 
    next = current->next; 
    current->next = prev; 
    prev = current; 
    current = next; 
    count++; 
    } 
      
    /* 2) Now head points to the kth node. 
    So change next  of head to (k+1)th node*/
    if(head != NULL) 
    head->next = current; 
  
    /* 3) We do not want to reverse next k 
       nodes. So move the current 
        pointer to skip next k nodes */
    count = 0; 
    while(count < k-1 && current != NULL ) 
    { 
    current = current->next; 
    count++; 
    } 
  
    /* 4) Recursively call for the list 
    starting from current->next. And make
    rest of the list as next of first node */
    if(current != NULL) 
    current->next = kAltReverse(current->next, k); 
  
    /* 5) prev is new head of the input list */
    return prev; 
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
    cout<<"reverse alternate every 3 nodes of above Linked list\n";
    head=kAltReverse(head,3);
    printList(head);

return 0;
}

