#include<iostream>
#include<vector>
#include<queue>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
Node(int val){
    data = val;
    left = NULL;
    right = NULL;
}
};

void constructDLL(Node *root,Node *head,Node *tail){
    if(!root) return;

    constructDLL(root->left,head,tail);
    
    if(!head) head = root;

    root -> left = tail;

    if(!tail) tail ->right = root;
    tail = root;

    constructDLL(root->right,head,tail);

}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head=NULL;
    Node *tail = NULL;

    constructDLL(root,head,tail);

    printList(root);
    return 0;
}
