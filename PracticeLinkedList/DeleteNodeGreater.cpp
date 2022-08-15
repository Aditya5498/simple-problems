// //Delete nodes which have a greater value on right side -> https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
// Examples: 
// a) The list 12->15->10->11->5->6->2->3->NULL should be changed to 15->11->6->3->NULL. Note that 12, 10, 5 and 2 have been deleted because there is a greater value on the right side. 
//(12,15,10,11,5,6,2,3)              
//(15,15,11,11,6,6,3,3) 
//
//When we examine 12, we see that after 12 there is one node with a value greater than 12 (i.e. 15), so we delete 12. 
// When we examine 15, we find no node after 15 that has a value greater than 15, so we keep this node. 
// When we go like this, we get 15->6->3
// b) The list 10->20->30->40->50->60->NULL should be changed to 60->NULL. Note that 10, 20, 30, 40, and 50 have been deleted because they all have a greater value on the right side.
// c) The list 60->50->40->30->20->10->NULL should not be changed. 

// //Solution
// Come from back and make a new list that shows max until now value
// and then compare if the current value is lesser than the correspoding value in the array. If yes, delete the element
//Method : Use a stack to store the max until now value and the pop all the values and store it in a vector
// Time Complexity: O(n)

#include <iostream>
#include <stack>
#include <vector>
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

//Printing the linked list
void printList(Node *head){
    if(head==NULL) cout<<"NULL node\n";
    while(head){
        cout<<head->val;
        if(head->next) cout<<" -> ";
        head=head->next;
    }
    cout<<endl;
}

// stack to store the max until now values
stack<int> st;
int maxUntilNow=0;
void storeMax(Node *head){
    if(head){
        storeMax(head->next);
        if(head->next==NULL) maxUntilNow=head->val;
        else maxUntilNow=head->val>maxUntilNow?head->val:maxUntilNow;
        st.push(maxUntilNow);
    }
}

//vector to store stack values
vector<int> values;
void storeV(){
    while(!st.empty()){
        values.push_back(st.top());
        st.pop();
    }
}


Node* deleteNodes(Node *head){
   storeMax(head);
    storeV();
    Node *curr=head,*prev=NULL;
    int idx=0;
    while(curr){
        if(curr->val<values[idx]){
            if(curr==head){
                prev=head;
                head=head->next;
                curr=head;
                delete prev;
                prev=NULL;
            }
            else{
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
            }
        }
        else {
            prev=curr;
            curr=curr->next;
        }
        idx++;
    }
    return head;
}

int main(){
    cout<<"NEW list to delete the nodes\n";
    //calling and using the deleteNodes function
    Node *test=new Node(12);
    test->next=new Node(15);
    test->next->next=new Node(10);
    test->next->next->next=new Node(11);
    test->next->next->next->next=new Node(5);
    test->next->next->next->next->next=new Node(6);
    test->next->next->next->next->next->next=new Node(2);
    test->next->next->next->next->next->next->next=new Node(3);
    printList(test);
    test=deleteNodes(test);
    cout<<"After deleting the nodes\n";
    printList(test);
    return 0;
}