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

    TreeNode *root = constructTree(head);

    printInOrder(root);
    return 0;
}
