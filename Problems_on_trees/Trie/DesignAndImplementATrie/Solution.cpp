#include<iostream>

using namespace std;

struct TrieNode{
TrieNode *child[26];
bool isEndOfWord;

TrieNode(){
    for(int i=0;i<26;i++) child[i] = nullptr;
    isEndOfWord = false;
}
};

void insert(TrieNode *root, string key){
    for(int i=0;i<key.size();i++){
        if(root->child[key[i] - 'a'] == NULL)  {
            cout<<"Inserting "<<key[i]<<" at\t"<<key[i]-'a'<<endl;
            root -> child[key[i] - 'a'] = new TrieNode();
        }
         root = root->child[key[i] - 'a'];
    }
    root -> isEndOfWord = true;
}

void printWords(TrieNode *root){
    while(root){
    for(int i=0;i<26;i++){
        if(root->child[i]){
            char c = 'a' + i;
            cout<<c<<" ";
    root = root ->child[i];
        }
    }
    if(root->isEndOfWord) break;
    }
}

int main(){
    TrieNode *root = new TrieNode();
    string t = "teat";
    insert(root,t);
    t = "marks";
    insert(root, t);
    printWords(root);
    return 0;
}