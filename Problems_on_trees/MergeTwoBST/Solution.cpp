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

void inOrder(Node *root,vector<int> &arr){
    if(!root) return;
    inOrder(root->left,arr);
    arr.push_back(root->data);
    inOrder(root->right,arr);
}

vector<int> merge2arrays(vector<int> arr1, vector<int> arr2){
    vector<int> finalArray;
    int i=0,j=0;
    while(i<arr1.size() || j<arr2.size()){
        if(arr1[i] < arr2[j]){
            finalArray.push_back(arr1[i]);
            i++;
        }
        else{
            finalArray.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        finalArray.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        finalArray.push_back(arr2[j]);
        j++;
    }
    return finalArray;
}

void printArray(vector<int> arr){
   for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
vector<int> arr1;
vector<int> arr2;
vector<int> finalArray;
Node *root1 = new Node(10);
root1 ->left = new Node(5);
root1 ->right = new Node(25);

Node *root2 = new Node(20);
root2->left = new Node(14);
root2->right = new Node(21);

inOrder(root1,arr1);
inOrder(root2,arr2);

finalArray = merge2arrays(arr1,arr2);

printArray(arr1);
printArray(arr2);
printArray(finalArray);
    return 0;
}