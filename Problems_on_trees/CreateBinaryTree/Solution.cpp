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

int maxIdx(vector<int> &arr, int start, int end){
    int maxIndex = arr[start];
    for(int i=start;i<end;i++)
        if(arr[i] > arr[maxIndex]) maxIndex = i;
    
    return maxIndex;
}

Node* constructTree(vector<int> &arr,int start,int end){
    if(start > end) return NULL;

    // Find the max index from the array in the given range
    int maxIndex = maxIdx(arr,start,end);

    // Create a node of the max Index location
    Node *root = new Node(arr[maxIndex]);

    // if this is the only element left out, then return it
    if(start == end) return root;

    // using the max index, split the array into 2 halves and construct a new node for
    // the maximum values found in that range
    root ->left = constructTree(arr,start,maxIndex-1);
    root->right = constructTree(arr,maxIndex+1,end);

    return root;
}

void printInOrder(Node *root){
    if(!root) return;
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main(){
    vector<int> arr = {5,10,40,30,28};
    Node *root = constructTree(arr,0,arr.size());
    printInOrder(root);
    return 0;
}