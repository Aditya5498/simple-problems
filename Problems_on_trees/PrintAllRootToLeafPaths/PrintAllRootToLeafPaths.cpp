#include<iostream>
#include<vector>

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

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++)
    cout<<arr[arr.size()-1-i]<<" ";
    cout<<endl;
}

void dfs(Node *root,vector<int> arr){
    if(!root) return;
    
    cout<<root->data<<" ";
    print(arr);
    arr.push_back(root->data);
    dfs(root->left,arr);
    dfs(root->right,arr);
}

int main() {
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);
vector<int> arr;
dfs(root,arr);
    return 0;
}