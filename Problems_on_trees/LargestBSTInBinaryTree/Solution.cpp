#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
Node(int val){
    data = val;
    left = right = nullptr;
}
};

int result = 0;
int largestBST(Node *root){
    if(!root) return 0;
int left = largestBST(root->left);
    int right = largestBST(root->right);
        cout<<"At node "<<root->data<<" count of left = "<<left<<" & count of right = "<<right<<endl;
    result = result + max(left,right);

     if( (!root -> left && !root->right) ||
     (root->left->data > root->data || root->right->data < root->data)) return 1;

     else if((root->left->data < root->data && !root->right) || 
    (root->right->data > root->data && !root->left)) return 2;

    return 3;
}

int main(){
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    largestBST(root);
    cout<<"Size of largest BST is "<<result;
    return 0;
}