// The approach to convert binary tree a ciruclar linked list is lie below,
// First, convert the binary tree to a doubly linked list 
// and then point the last node to the first node
// DO a inorder traversal and convert the node into a doubly linked list node

// You can find the program from here -> https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/
#include <iostream>
using namespace std;
 
/* A binary tree node has - data , left and right pointers */
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// A utility function that converts given binary tree to
// a doubly linked list
// root --> the root of the binary tree
// head --> head of the created doubly linked list
Node *BTree2DoublyLinkedList(Node *root, Node **head)
{
    // Base case
    if (root == NULL)
      return root;
 
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static Node* prev = NULL;
 
    // Recursively convert left subtree
    BTree2DoublyLinkedList(root->left, head);
 
    // Now convert this node
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
 
    // Finally convert right subtree
    BTree2DoublyLinkedList(root->right, head);
    return prev;
}
// A simple recursive function to convert a given Binary tree to
// Circular Doubly Linked List using a utility function
// root --> Root of Binary Tree
// tail --> Pointer to tail node of created circular doubly linked list
Node* BTree2CircularDoublyLinkedList(Node *root)
{
    Node *head = NULL;
    Node *tail = BTree2DoublyLinkedList(root, &head);
    // make the changes to convert a DLL to CDLL
    tail->right = head;
      head->left = tail;
      // return the head of the created CDLL
      return head;
}
 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
Node* newNode(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 
/* Function to print nodes in a given circular doubly linked list */
void printList(Node *head)
{
    if(head==NULL)
      return;
      Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->right;
    }while(ptr!=head);
}
 
/* Driver program to test above functions*/
int main()
{
    // Let us create the tree shown in above diagram
    Node *root     = newNode(10);
    root->left     = newNode(12);
    root->right     = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    // Convert to DLL
    Node *head = BTree2CircularDoublyLinkedList(root);
 
    // Print the converted list
    printList(head);
 
    return 0;
}
 