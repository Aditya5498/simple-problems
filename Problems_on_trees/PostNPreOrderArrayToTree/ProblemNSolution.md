Construct Full Binary Tree from given preorder and postorder traversals.

Given two arrays that represent preorder and postorder traversals of a full binary tree, construct the binary tree. Full Binary Tree is a binary tree where every node has either 0 or 2 children.

Illustration: Following are examples of Full Trees. 

        1
      /   \
    2       3
  /  \     /  \
 4    5   6    7


       1
     /   \
   2      3
        /   \  
       4     5
           /   \  
          6    7
                  

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \  
8    9 
It is not possible to construct a general Binary Tree from preorder and postorder traversals.
But if know that the Binary Tree is Full, we can construct the tree without ambiguity.

Solution :- O(n)

We know that the 1st element of the preorder list is always the root.
Hence take this element as the root, and since this is a FULL Binary Tree, 
we can take the next 2 elements as the left and right nodes subsequently.
Also, if we consider the 1st element of preorder and find it in post order, 
the left of the element is on the left side of the root and the right side
of the element is on the right side of the root.
For example,
Let us consider the two given arrays as pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1}; 
In pre[], the leftmost element is root of tree. Since the tree is full and array size is more than 1. The value next to 1 in pre[], must be left child of root. So we know 1 is root and 2 is left child. How to find the all nodes in left subtree? We know 2 is root of all nodes in left subtree. All nodes before 2 in post[] must be in left subtree. Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree, and the elements {6, 7, 3} are in right subtree. 

                  1
                /   \
               /      \
     {8, 9, 4, 5, 2}     {6, 7, 3}
We recursively follow the above approach and get the following tree. 

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
  / \  
 8   9  