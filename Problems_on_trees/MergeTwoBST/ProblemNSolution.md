You are given two balanced binary search trees e.g., AVL or Red-Black Tree. Write a function that merges the two given balanced BSTs into a balanced binary search tree. Let there be m elements in the first tree and n elements in the other tree. Your merge function should take O(m+n) time.
In the following solutions, it is assumed that the sizes of trees are also given as input. If the size is not given, then we can get the size by traversing the

Solution :- Space = O(m+n)
Make 2 different array.
In the first array, take the inorder traversal of first BST which will give the sorted order.
In the second array, take the inorder traversal of the second BST which will give the sorted order of second BST.
Now, merge the 2 sorted array's.
With the new merged sorted array, create a BST from this new array.
