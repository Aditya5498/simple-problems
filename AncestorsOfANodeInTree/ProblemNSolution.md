Problem:- 

Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree. 

For example, if the given tree is following Binary Tree and key is 7, then your function should print 4, 2 and 1.
              1
            /   \
          2      3
        /  \
      4     5
     /
    7

Solution :-

Find the element using in order traversal and once you get the element, bactrack to the original root node and print them.