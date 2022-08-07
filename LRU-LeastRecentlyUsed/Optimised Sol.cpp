// The LRU can be optimised to obtain O(1) for get operation and O(1) for put operation.
// The idea is to use doubley linked list and a hash table
// DOUBLY linked list to traverse through and fro
// hash table to store value and it's address.
// // So, when performing get operation -> check if the value is there in has table, 
// If yes -> then go to that address and modify the pointer so that it becomes the most recently viewed element
// If No -> return -1;

// When performing the put operation -> 
// - check if the capacity is already exceeded,then we will have to evoke the least 
// reused element, i.e, the first node of linked list and make the 2nd pointer as start and then add the new key value pair in the last
// - if the capacity is not fully used, then add the new element to the last node of doubly linked list

// In this program, Map library as has table

#include<iostream>
#include<map>
using namespace std;

// Capacity of cache
int capacity=2;

// Node
class Node{   

public:
 int val;
Node* next;
Node* prev;
Node(int val){
    val=val;
    next=prev=NULL;
}
Node(int val,Node *next,Node *prev){
    val=val;
    next=next;
    prev=prev;
}

};

// doubly linked list
class doublyLinkedList{
    int size;
    public:
    Node* first;
    Node* last;
     doublyLinkedList(){
        Node* node=new Node(0);
        first=node;
        last=node;
        size=0;
    }

    doublyLinkedList(int num){
        Node* node=new Node(num);
        first=node;
        last=node;
        size=1;
    }

    int getSize(){
        return size;
    }   

    Node* push(int val){
        if(size==0){
            first->val=val;
        }
        else{
        last->next=new Node(val);
        last->next->prev=last;
        last=last->next;
        }
        size++;
        return last;
    }

    void remove(Node* ptr){
        if(ptr==first)
            first=first->next;
        
        else if(ptr==last)
            last=last->prev;
        
        else{
            Node *temp=ptr;
            ptr->prev->next =temp->next;
            temp->next->prev=temp->prev;
        }
        delete ptr;
    }

    void print(){
    Node *temp=first;
    while(temp!=last){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    }
};

map<int,Node*> ht;
doublyLinkedList *test=new doublyLinkedList();

int get(int key){
    if(ht.find(key)!=ht.end()){
        Node* ptr=ht[key];
        test->remove(ptr);
        ht[key]=test->push(key);
        return key;
    }
return -1;
}

void put(int key){
if(test->getSize()<capacity){
    ht[key]=test->push(key);
}
else{
    test->remove(test->first);
    ht[key]=test->push(key);
}
}


int main(){
    capacity=3;
    put(1);
    put(2);
    put(3);
    put(4);
    test->print();
    get(2);
    get(1);
    test->print();
    return 0;
}


