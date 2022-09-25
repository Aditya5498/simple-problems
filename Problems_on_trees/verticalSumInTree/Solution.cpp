#include<iostream>
#include<map>

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

map<int,int> hm;

void dfs(Node *root, int horizontalDistance){
    if(!root) return;
dfs(root->left, horizontalDistance - 1);
hm[horizontalDistance] += root->data;
dfs(root->right, horizontalDistance + 1); 
}

void printHashMap(){
    auto it = hm.begin();
    while(it!=hm.end()){
        cout<<it->second<<" ";
        it++;
    }
}

int main(){
Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);
dfs(root,0);
printHashMap();
}