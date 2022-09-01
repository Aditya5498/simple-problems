#include<iostream>
#include<vector>
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


//Print all root to leaf nodes path
// Store the visited nodes in a array and traverse
// the tree if we reach the leaf nodes, Just print the array
//else add the existing node to the list
void printPath(Node *root, vector<int> &path, int len){
    if(!root) return;
    path.push_back(root->data);
    len++;
    if(!root->left && !root->right){
        for(int i=0;i<=len; i++) cout<<path[i]<<" -> ";
        cout<<endl;
    }
    else {    
    printPath(root->left, path, len);
    printPath(root->right, path, len);
    }
}

int main(){
 Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> path;
    printPath(root,path, 0);
   
    return 0;
}