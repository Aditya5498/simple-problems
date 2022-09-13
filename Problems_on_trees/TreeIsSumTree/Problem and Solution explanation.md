Check if a given Binary Tree is SumTree 😀😅

Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree. 

          26
        /   \
      10     3
    /    \     \
  4      6      3

Solution O(n) :-

do a preorder traversal, and for every node check
i) If the node is leaf node, then return true
ii) If the root's left and right nodes are leaf nodes, then return true if the sum is same as leaf nodes
ii) Else if sum of both the child nodes is 2 * the root node, then return true
Else return False

The program which I wrote has logical errors, but this is my first thought out program