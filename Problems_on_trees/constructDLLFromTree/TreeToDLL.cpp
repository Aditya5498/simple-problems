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

//The idea is to do in-order traversal of the binary tree. While doing inorder traversal, keep track of the previously visited node in a variable, say prev. For every visited node, make it next to the prev and set previous of this node as prev.


void constructDLL(Node *root,Node *head){
if(!root) return;

static Node *prev = NULL;

constructDLL(root->left,head);

if(!head) head = root;
else {
    root -> left = prev;
    prev->right = root;
}
prev = root;

constructDLL(root->right,head);

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

    constructDLL(root,head);

    printList(root);
    return 0;
}
