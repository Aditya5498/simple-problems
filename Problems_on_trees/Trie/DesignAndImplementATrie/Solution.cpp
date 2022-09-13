#include<iostream>

using namespace std;

struct TrieNode{
TrieNode *child[26];
bool isEndOfWord;

TrieNode(){
    for(int i=0;i<26;i++) child[i] = NULL;
    isEndOfWord = false;
}
};

void insert(TrieNode *root, string key){
    for(int i=0;i<key.size();i++){
        if(root->child[key[i] - 'a'] == NULL)  root -> child[key[i] - 'a'] = new TrieNode();
         root = root->child[key[i] - 'a'];
    }
    root -> isEndOfWord = true;
}

int main(){
    return 0;
}