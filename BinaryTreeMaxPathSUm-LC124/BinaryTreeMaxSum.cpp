#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int result=0;

int dfs(TreeNode *root){
    if(!root) return 0;
     int left=dfs(root->left);
        int right=dfs(root->right);
        left=max(left,0);
        right=max(right,0);
    
        result=max(result,left+right+root->val);
        return root->val+max(left,right);
}

int maxSum(TreeNode *root){
    result=root->val;
    dfs(root);
    return result;
}

int main(){
    TreeNode *root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<maxSum(root);
    return 0;
}
