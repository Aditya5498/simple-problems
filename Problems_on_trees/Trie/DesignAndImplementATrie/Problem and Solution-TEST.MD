Problem :- 
😀😆😄😅😑😣😏
Design and implement Trie.
Trie is an efficient information retrieval data structure.
Using Trie, search complexities can be brought to optimal limit (key length). 
If we store keys in a binary search tree, a well balanced BST will need time proportional to M * log N, where M is the maximum string length and N is the number of keys in the tree.
Using Trie, we can search the key in O(M) time.

Solution :-

Every node of Trie consists of multiple branches. Each branch represents a possible character of keys. We need to mark the last node of every key as the end of the word node. A Trie node field isEndOfWord is used to distinguish the node as the end of the word node. A simple structure to represent nodes of the English alphabet can be as follows, 
// Trie node 
struct TrieNode 
{ 
     struct TrieNode *children[ALPHABET_SIZE];
     // isEndOfWord is true if the node 
     // represents end of a word 
     bool isEndOfWord; 
}; 

Inserting a key into Trie is a simple approach. 
Every character of the input key is inserted as an individual Trie node.
Note that the children is an array of pointers (or references) to next level trie nodes.
The key character acts as an index to the array children. 
If the input key is new or an extension of the existing key, we need to construct non-existing nodes of the key, and mark the end of the word for the last node. 
If the input key is a prefix of the existing key in Trie, we simply mark the last node of the key as the end of a word. 
The key length determines Trie depth. 