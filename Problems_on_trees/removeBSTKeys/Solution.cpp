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

Node* removeOutsideRange(Node *root,int min, int max){
    if(!root) return NULL;

    root->left = removeOutsideRange(root->left,min,max);
    root->right = removeOutsideRange(root->right,min,max);

    if(root->data < min){
        Node *subTree = root ->right;
        delete root;
        return subTree;
    }

    else if(root->data > max){
        Node *subTree = root->left;
        delete root;
        return subTree;
    }
    return root;
}

void printInOrder(Node *root){
    if(!root) return;

    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

// A utility function to insert a given key to BST
Node* insert(Node* root, int key)
{
    if (root == NULL)
       return new Node(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}

int main(){
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    printInOrder(root);
 
    root = removeOutsideRange(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    printInOrder(root);
    return 0;
}