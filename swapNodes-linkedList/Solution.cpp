#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data1){
        data=data1;
        next=NULL;
    }
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
};

void print(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data;
        if(temp->next) cout<<"->";
        temp=temp->next;
    }
}

Node* swapNodes(Node *head){
    // If linked list is empty or 
    // there is only one node in list
    if (head == NULL || head->next == NULL)
        return head;
   
    // Initialize previous and current pointers
    Node* prev = head;
    Node* curr = head->next;
   
    head = curr; // Change head before proceeding
   
    // Traverse the list
    while (true) {
        Node* next = curr->next;
        curr->next = prev; // Change next of
        // current as previous node
   
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
   
        // Change next of previous to next of next
        prev->next = next->next;
   
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
    return head;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    print(head);
    head=swapNodes(head);
    cout<<"\n After Swapping the nodes\n";
    print(head);
        return 0;
}