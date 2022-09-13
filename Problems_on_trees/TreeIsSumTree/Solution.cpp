#include<iostream>

using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node(int data1){
data = data1;
left = right = NULL;
}
};

bool isLeaf(Node *root){
    if(!root) return false;
    if(!root -> left && !root -> right) return true;
    return false;
}

bool isTreeSum(Node *root){
    if(!root) return true;
    if(!root -> left && !root -> right) return true;
    else {        
        if(isLeaf(root ->left) || isLeaf(root -> right)){
            int sum = 0;
            if(root ->left) sum+=root ->left ->data;
            if(root ->right) sum+= root->right->data;
            return sum == root ->data;
        }
        int sum = 0;
        if(root -> left) sum+= root -> left ->data;
        if(root->right) sum+= root -> right ->data;
        cout<<"Sum "<<sum<<" & root data = "<<root->data<<endl;
        return 2*sum == root -> data && isTreeSum(root->left) && isTreeSum(root->right);
    }
    return false;
}


int main(){
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    cout<<" Check if the Tree is Sum Tree\n"<<isTreeSum(root)<<endl;
    return 0;
}