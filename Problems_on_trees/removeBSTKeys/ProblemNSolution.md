Remove BST keys outside the given range

Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST. 


SOlution :-

Key Removal outside a given range using Post-Order Traversal
The idea is

Fix the tree in a Post-order fashion. When we visit a node, we make sure that its left and right sub-trees are already fixed. 

While traversing the tree there are two possible cases for every node. 

Node’s key is outside the given range. This case has two sub-cases. 
Node’s key is smaller than the min value. 
Node’s key is greater than the max value. 
Node’s key is in range.
We don’t need to do anything for case 2. In case 1, we need to remove the node and change the root of the subtree rooted with this node. 

In case 1 part 1, we simply remove the root and return the right sub-tree as a new root. 
In case 1 part 2, we remove the root and return the left sub-tree as a new root.