#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;

Node(int data1){
    data = data1;
    left=right=NULL;
}
};

// Convert a Binary Tree into its Mirror Tree
// Solution :- Using DFS like preOrder or PostOrder traversal, swap the left and right nodes
void mirror(Node *root){
Node *temp;
if(!root) return ;
temp=root->left;
root->left=root->right;
root->right=temp;
mirror(root->left);
mirror(root->right);
}

//print preorder traversal(DFS)
void printTree(Node *root){
    if(!root) return ;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
 Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    printTree(root);
    cout<<endl;
    mirror(root);
    printTree(root);
    cout<<endl;
    return 0;
}