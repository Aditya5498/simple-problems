#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
Node(int val){
    data = val;
    left = NULL;
    right = NULL;
}
};

int result = INT_MIN;
vector<int> gArray(0,0);

void dfs(Node *root,int sum,vector<int> arr){
    if(!root) return;
if(!root->left && !root->right) {
    if(sum+root->data > result)
    {
   result = sum+root->data;
    gArray.resize(arr.size());
   for(int i=0;i<arr.size();i++){ 
    gArray[i] = arr[i];
   }
   cout<<endl;
}
}
else{
    arr.push_back(root->data);
    dfs(root->left,sum+root->data,arr);
    dfs(root->right,sum+root->data,arr);
}
}

int main(){
Node *root = new Node(10);
root -> left = new Node(-2);
root->right = new Node(7);
root->left->left = new Node(8);
root->left->right = new Node(-4);
vector<int> arr;
dfs(root,0,arr);
cout<<result<<endl;
for(int i=0;i<gArray.size();i++) cout<<gArray[i]<<" ";
    return 0;
}