#include<iostream>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
Node(int data){
    val = data;
    left = nullptr;
    right = nullptr;
}
};

int toSumTree(Node *root){
    if(!root) return 0;

    int old_val = root->val;

    root->val = toSumTree(root -> left)+toSumTree(root -> right);

    return root->val+old_val;

}

void printInOrder(Node *root){
    if(!root) return;
    printInOrder(root->left);
    cout<<root->val<<" ";
    printInOrder(root->right);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    printInOrder(root);

    toSumTree(root);
    cout<<endl;
    printInOrder(root);

    return 0;
}