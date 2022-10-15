#include<iostream>
using namespace std;

struct TreeNode {
     char data;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : data('A'), left(nullptr), right(nullptr) {}
     TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
      TreeNode(char x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
  };

int search(char arr[],int start, int end, char chr){
    int idx = 0;
    for(int i=start;i<=end;i++){
        if(arr[i] == chr) return i;
    }
    return idx;
}

TreeNode* buildTree(char in[],char pre[],int start, int end){
    static int preIndex = 0;
      if(start > end) return NULL;
    TreeNode *root = new TreeNode(pre[preIndex++]);
    if(start == end) return root;
    
    int inIdx = search(in,start,end,root->data);
    
    root->left = buildTree(in,pre,start,inIdx-1);
    root->right = buildTree(in,pre,inIdx+1,end);
    
    return root;
  
}

void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout<<node->data<<" ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 

int main() {
   char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    TreeNode* root = buildTree(in, pre, 0, len - 1);
 
    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);

    return 0;
}