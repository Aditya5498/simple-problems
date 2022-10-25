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

    void DFS(int v, const int& d, bool& ans){  
        if(ans) cout<<"\nANSWER has been found at vertex "<<v<<" & d ="<<d<<endl; 
        if(!visited[v]){
            if(v == d) {
                cout<<"Found a match at vertex "<<v<<" == "<<d<<endl;
                ans = true;
                return;
                }
            visited[v] = true;
            for(auto it = adjacencyList[v].begin(); it!= adjacencyList[v].end();it++)
                     DFS(*it,d,ans);
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

    bool findPath(int v,int d){
        visited.clear();
        bool ans = false;
        DFS(v,d,ans);
        return ans;
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
    cout<<endl;
    cout<<"There's ";
    if(!g.findPath(0,3)) cout<<"NO";
    else cout<<"is";
    cout<<" path between 0 & 3 ";
    return 0;
}