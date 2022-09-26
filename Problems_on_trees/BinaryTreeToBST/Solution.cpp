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

void inOrder(Node *root, vector<int> &arr){
    if(!root) return;
    inOrder(root,arr);
    arr.push_back(root->data);
    inOrder(root,arr);
}

void inOrder(Node *root, vector<int> arr, int idx){
    if(!root) return;
    inOrder(root,arr,idx);
    root->data = arr[idx];
    idx++;
    inOrder(root,arr,idx);
}

void convertBinaryTreeToBST(Node *root){
vector<int> arr;
inOrder(root,arr);
sort(arr.begin(),arr.end());
cout<<"Sorted Array is:\n";
for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
cout<<endl;
//inOrder(root,arr,0);
}


int main(){
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);
    convertBinaryTreeToBST(root);
    cout<<root->data<<endl;
    cout<<root->left->data<<" "<<root->right->data<<endl;
    cout<<root->left->left->data<<" "<<root->left->right->data<<" "
    <<root->right->left->data<<" "<<root->right->right->data<<endl;
    return 0;
}