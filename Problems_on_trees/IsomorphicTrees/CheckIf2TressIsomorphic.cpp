#include<iostream>
#include<vector>
#include<queue>
#include <bits/stdc++.h>

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

bool areIsomorphic(Node *n1,Node *n2){
    if(!n1 && !n2) return true;

    if((!n1 && n2) || (n1 && !n2)) return false;

    if(n1 -> data != n2->data) return false;

    return (areIsomorphic(n1->left,n2->left) && areIsomorphic(n1->right,n2->right)
            || areIsomorphic(n1->right,n2->left) && areIsomorphic(n1->right,n2->left));
}

int main(){
     struct Node *n1 = new Node(1);
    n1->left        = new Node(2);
    n1->right       = new Node(3);
    n1->left->left  = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left  = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);
 
    struct Node *n2 = new Node(1);
    n2->left         = new Node(3);
    n2->right        = new Node(2);
    n2->right->left   = new Node(4);
    n2->right->right   = new Node(5);
    n2->left->right   = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);
 
    if (areIsomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";
 
    return 0;
}