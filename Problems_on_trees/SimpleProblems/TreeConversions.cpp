#include<iostream>
#include<math.h>
#include<queue>
#include "bits/stdc++.h"
using namespace std;

struct TreeNode{
int data;
TreeNode *left;
TreeNode *right;

TreeNode(int data1){
    data = data1;
    left=right=NULL;
}
};

// Convert Preorder and inorder traversals to a binary tree -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/2476034/C%2B%2B-clean-solution-for-beginner-or-recursion-with-single-index
// Video explanation -> https://www.youtube.com/watch?v=ihj4IQGZ2zc
   int idx = 0; // index for preorder array
	
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l > r)
            return NULL;
        if(l == r)
            return new TreeNode(preorder[idx]);
        if(idx >= preorder.size())
            return NULL;
        
        int val = preorder[idx];
        TreeNode* root = new TreeNode(val);
		
		// find the root val in inorder array
        int mid = find(inorder.begin(), inorder.end(), val) - inorder.begin(); 
        
		// if there is a left subtree to build
        if(mid - 1 >= l){
            idx ++;
            root->left = build(preorder, inorder, l, mid-1);
        }
		
		// if there is a right subtree to build
        if(mid + 1 <= r){
            idx ++;
            root->right = build(preorder, inorder, mid+1, r);
        }
        
        return root;
    }

// Calling function
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1);
    }

//Print level order
void getLevelOrder(TreeNode *root,vector<TreeNode*> &arr){
if(!root) return;
queue<TreeNode*> q;
q.push(root);
q.push(new TreeNode(12345));
while(!q.empty()){    
    TreeNode *temp = q.front();
      
    if(temp->data == 12345) {
        arr.push_back(new TreeNode(12345));
    }
    else 
    {
    arr.push_back(temp);  
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
    q.push(new TreeNode(12345));
    }
    q.pop();
}

cout<<endl;
}

void printLevelOrder(TreeNode *root){
    vector<TreeNode*> arr;
    getLevelOrder(root,arr);

    for(int i=0;i<arr.size();i++){
        if(arr[i]->data == 12345) cout<<endl;
        else cout<<arr[i]->data<<" ";
    }
}


int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *root=buildTree(preorder, inorder);
    printLevelOrder(root);
    return 0;
}