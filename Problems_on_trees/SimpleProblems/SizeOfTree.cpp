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

//Size() function recursively calculates the size of a tree. It works as follows:
//Size of a tree = Size of left subtree + 1 + Size of right subtree.
int size(Node *root){
if(!root) return 0;
return size(root->left) + size(root->right) + 1;
}

// Diameter of a binary tree
int diameter(Node *root, int &dia){
if(!root) return 0;
int left=diameter(root->left, dia);
int right=diameter(root->right, dia);
dia = max(dia, left+right+1);
return max(left, right)+1;
}

// Height of a tree -> take max of left sub tree and right sub tree +1
int height(Node *root){
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// level order traversal - traverse the tree by every level using queue
//Printing the tree by level order traversal
void PrintLevelOrder(Node *root){
     if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
    cout<<endl;
}

int main(){
    //Size of a tree is the number of elements present in the tree. 
    //Size of the below tree is 5. 
    Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<"\n\t\t******** Level Order Traversal *********\n";
    PrintLevelOrder(root);
    cout<<" Size = "<<size(root)<<endl;
    cout<<"Height = "<<height(root)<<endl;

    int dia = 0;
    int height = diameter(root,dia);
    cout<<"Diameter of the tree is "<<dia<<"\theight of the tree is : "<<height;

    return 0;
}