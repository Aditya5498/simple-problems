#include<iostream>

using namespace std;

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : data(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

bool printAncestors(TreeNode *root, int val){
    if(!root) return false;

    if(root -> data == val) return true;

    if(printAncestors(root -> left, val) || printAncestors(root -> right, val))
     {
        cout<< root->data <<" ";
        return true;
     }

    return false;
}

int main(){
struct TreeNode *root = new TreeNode(1);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->left->left  = new TreeNode(7);
 
  printAncestors(root, 7);
    return 0;
}