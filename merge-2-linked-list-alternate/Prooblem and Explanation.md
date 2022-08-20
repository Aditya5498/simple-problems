Merge a linked list into another linked list at alternate positions

Given two linked lists, insert nodes of second list into first list at alternate positions of first list. 
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place. Expected time complexity is O(n) where n is number of nodes in first list. 

Web link -> https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/

Solution :- O(n)

The idea to keep 2 head pointers one for linked list 1 and linked list 2,
while we reach the end of the node of linked list 1 simultanously ass each node of linked list 2 after moving ahead of the node, 
once we reach end of linked list 1 add the remaining nodes of linked list 2 to linked list 2

Check for boundary counditions like:-
1) if linked list 1 is empty, return linked list 2
2) if linked list 2 is empty, return linked list 2
