#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;

Node(int data1){
    data = data1;
    left=right=nullptr;
}
};


//Print all root to leaf nodes path
// Store the visited nodes in a array and traverse
// the tree if we reach the leaf nodes, Just print the array
//else add the existing node to the list
void printPath(Node *root, vector<int> path, int len){
    if(!root) return;
    path.push_back(root->data);
    len++;
    if(!root->left && !root->right){
        for(int i=0;i<len; i++) cout<<path[i]<<" ";
        cout<<endl;
    }
    else {    
    printPath(root->left, path, len);
    printPath(root->right, path, len);
    }
}

//Print level order

void getLevelOrder(Node *root,vector<Node*> &arr){
if(!root) return;
queue<Node*> q;
q.push(root);
q.push(new Node(12345));
while(!q.empty()){    
    Node *temp = q.front();
      
    if(temp->data == 12345) {
        arr.push_back(new Node(12345));
    }
    else 
    {
    arr.push_back(temp);  
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
    q.push(new Node(12345));
    }
    q.pop();
}

cout<<endl;
}

void printLevelOrder(Node *root){
    vector<Node*> arr;
    getLevelOrder(root,arr);

    for(int i=0;i<arr.size();i++){
        if(arr[i]->data == 12345) cout<<endl;
        else cout<<arr[i]->data<<" ";
    }
}

// Count Leaf nodes in a binary tree
int count(Node *root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    else return count(root->left) + count(root->right);
}

//Check if a tree is BST - Inorder traversal of the tree and check if the numbers has been sorted.
void inOrder(Node *root,vector<Node*> &q){
    if(!root) return;
    inOrder(root->left,q);
    q.push_back(root);
    inOrder(root->right,q);
}

// root to leaf path sum
bool rootToLeafPathSum(Node *root,int sum){
    if(!root) return false;
    if(!root->left && !root->right) return sum-root->data == 0;
    return rootToLeafPathSum(root->left,sum-root->data) || rootToLeafPathSum(root->right,sum-root->data);
}

// check if a tree is foldable :- SOL - 
// (Check if Left and Right subtrees are Mirror) 

// There are mainly two functions:
// Checks if tree can be folded or not 

// IsFoldable(root)
// 1) If tree is empty then return true
// 2) Else check if left and right subtrees are structure wise mirrors of
//     each other. Use utility function IsFoldableUtil(root->left,
//     root->right) for this.
// Checks if n1 and n2 are mirror of each other. 

// IsFoldableUtil(n1, n2)
// 1) If both trees are empty then return true.
// 2) If one of them is empty and other is not then return false.
// 3) Return true if following conditions are met
//    a) n1->left is mirror of n2->right
//    b) n1->right is mirror of n2->left

bool isFoldableUtil(Node *l, Node *r){
    if(!l && !r) return true;
    if(!l || !r) return false;
    return isFoldableUtil(l->left, r->right) && isFoldableUtil(l->right, r->left);
}

bool isFoldable(Node *root){
    if(!root) return true;
    return isFoldableUtil(root->left, root->right);
}

int main(){
 Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> path;
    printPath(root,path, 0);
    cout<<" ------------ ******** -----------\n\tLever Order traversal\n";
    printLevelOrder(root);
    cout<<" ------------ ******** -----------\n\tNumber of leaf nodes = "<<count(root)<<endl;
    
    // Check if a tree is BST -> Approach: Store the Nodes while travesring the tree 
    //through inorder traversal and then check if the nodes have been stored in an ascending order
    vector<Node*> arr;
    bool flag=true;
    inOrder(root,arr);
    for(int i=1;i<arr.size();i++){
        if(arr[i]->data < arr[i-1]->data){
            cout<<"Tree is not a BST\n";
            flag=false;
            break;
        }
    } 
    if(flag)
        cout<<"Tree is a BST\n";
       

    // root to leaf path sum
    cout<<"Check if there exists a path sum of(root to leaf) "<<3<<" : "<<rootToLeafPathSum(root,3); 
     return 0;
}