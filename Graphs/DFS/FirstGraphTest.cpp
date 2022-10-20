#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;

class Graph{
    public:
    // creating a visited array to keep check of visted vertices
    map<int,bool> visited;
    //creating a adjacency list used for vertices
    map<int,vector<int>> adjacencyList;

    void addEdge(int v,int e){
        adjacencyList[v].push_back(e);
    }

    void print(){
        for(auto itr = adjacencyList.begin();itr!=adjacencyList.end();itr++){
            for(int i=0;i<itr->second.size();i++)
                cout<<itr->first<< "->"<<itr->second[i]<<endl;
        }
    }

    void DFS(int v){   
        if(!visited[v]){
             cout<<v<<" ";
            visited[v] = true;
            for(auto it = adjacencyList[v].begin(); it!= adjacencyList[v].end();it++)
                     DFS(*it);
        }
    }

    void BFS(int v){
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while(!q.empty()){
            int num = q.front();
            cout<<num<<" ";
            q.pop();

            for(auto i:adjacencyList[num]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void clearVisited(){
        visited.clear();
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"Printing the vertices and it's connected edges\n";
    g.print();
    cout<<"Printing the DFS\n";
    g.DFS(2);
    g.clearVisited();
    cout<<"\nPrinting BFS\n";
    g.BFS(2);
    return 0;
}