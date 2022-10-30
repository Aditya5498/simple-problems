https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> hm;

    Node* dfs(Node *node){
        if(!node) return NULL;

        if(hm[node]) return hm[node];

        Node *copy = new Node(node->val);
        hm[node] = copy;

        for(auto i:node->neighbors) copy->neighbors.push_back(dfs(i));
        return copy;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};