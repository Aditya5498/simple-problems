#include<iostream>
#include<vector>
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

Node* constructTree(int preOrder[], int postOrder[], int preOrderIdx, int left, int right, int size){
    // if the left index > right index and the index in the preOrder list 
    // has been exceeded over the size of the preOrder array then return null.
    if(left > right || preOrderIdx >= size) return NULL;

    //create the root node of that index and then increment the count
    Node *root = new Node(preOrder[preOrderIdx]);
    preOrderIdx++;
    
    // if we reach the last node, then return root
    if(left == right)
    return root;

    // search for the next element of preOrder in PostOrder
    int breakPoint=0;
    for(breakPoint=left;breakPoint<=right;breakPoint++)
        if(preOrder[preOrderIdx] == postOrder[breakPoint]) break;
    
    // we have the break point which separates the left half and right half in breakPoint
    // so now, recursively call the function to create the left and right nodes

    if(breakPoint<=right){
        root->left = constructTree(preOrder,postOrder,preOrderIdx,left,breakPoint,size);
        root->right = constructTree(preOrder,postOrder,preOrderIdx,breakPoint+1,right-1,size);
    }

    return root;

}

void printInOrder(Node *root){
    if(!root) return;

    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main(){
    
    int preOrder[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
    int postOrder[] = { 8, 9, 4, 5, 2, 6, 7, 3, 1 };
    int size = sizeof(preOrder) / sizeof(preOrder[0]);

    Node *root = constructTree(preOrder,postOrder,0,0,size-1,size);

    printInOrder(root);
    return 0;
}