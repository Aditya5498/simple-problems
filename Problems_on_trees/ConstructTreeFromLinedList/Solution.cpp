#include<iostream>
#include<vector>
#include<queue>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
TreeNode(int val){
    data = val;
    left = NULL;
    right = NULL;
}
};

struct Node{
    int data;
    Node *next;
Node(int val){
    data = val;
    next = NULL;
}
};

int countHeads(Node *head){
    int count = 0;
    while(!head) {
        count++;
        head=head->next;
    }
    return count;
}

// constructing a complete binary tree -> all the nodes will have at least 2 child nodes
TreeNode* constructTree(Node *head){
    TreeNode *root = new TreeNode(head->data);
    TreeNode *dummy;

    int count = 0, maxNodes = countHeads(head);
    Node *itr = head, *leftPtr = head, *rightPtr = head;

    queue<TreeNode*> q;
    q.push(root);

    while(count < maxNodes - 2){
        for(int i=0;i<2*count+1;i++)
        leftPtr = leftPtr->next;
        for(int i=0;i<2*count+2;i++)
        rightPtr = rightPtr->next;

        dummy = q.front();
        q.pop();

        dummy->left = new TreeNode(leftPtr->data);
        dummy->right = new TreeNode(rightPtr->data);

        q.push(dummy->left);
        q.push(dummy->right);

        count++;

    }
return root;
}


void convertList2BinaryTree(Node *head,TreeNode *&root){

queue<TreeNode*> q;

if(!head) {
    root = NULL;
    return;
}

root = new TreeNode(head->data);
q.push(root);

head=head->next;


while(head){
TreeNode *parent = q.front();
q.pop();

TreeNode *left = NULL, *right = NULL;
left = new TreeNode(head->data);
q.push(left);

head = head->next;

if(head){
    right = new TreeNode(head->data);
    q.push(right);
    head=head->next;
}

parent->left = left;
parent->right = right;
}


}


void printInOrder(TreeNode *root){
    if(!root) return ;
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main(){
    Node *head = new Node(10);
    head -> next = new Node (12);
    head -> next -> next= new Node (15);
    head -> next -> next-> next= new Node (25);
    head -> next -> next-> next-> next= new Node (30);
    head -> next-> next-> next-> next-> next = new Node (35);

    //TreeNode *root = constructTree(head);

    TreeNode *root;
    convertList2BinaryTree(head,root);
    printInOrder(root);
    return 0;
}
