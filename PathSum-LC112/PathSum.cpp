#include <iostream>
using namespace std;

int target=0;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

bool dfs(TreeNode *root,int currSum){
    if(!root) return false;
    currSum+=root->val;
    if(!root->left && !root->right)
        return currSum==target;
    
    return dfs(root->left,currSum) || dfs(root->right,currSum);
}

 bool hasPathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        return dfs(root,0);
    }

int main(){
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(1);
    cout<<hasPathSum(root,22);
    return 0;
}