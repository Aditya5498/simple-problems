#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Graph{
    public:
    map<int,vector<int>> vertices;
    map<int,bool> visited;

    int firstVertex(){
    auto it = vertices.begin();
    return it->first;
    }

    bool isCyclicUtil(int v,const int parent){
        if(!visited[v]){            
            visited[v] = true;            
            for(auto it = vertices[v].begin(); it!= vertices[v].end();it++)
            {
                cout<<"\nAt "<<*it<<" and it's parent is "<<parent;
                if(*it == parent) {
                    cout<<"\nFound a parent\n";
                    return true;
                }
                 isCyclicUtil(*it, parent);
            }
        }

        return false;
    }

    bool isCyclic(){
        bool check=false;
        for(auto it=vertices.begin();it!=vertices.end();it++){
            visited.clear();
            check|=isCyclicUtil(it->first,it->first);
            if(check) break;
        }
        return check;
    }
};

int main(){
    Graph g;
    g.vertices[0].push_back(1);
    g.vertices[0].push_back(2);
    g.vertices[1].push_back(2);
    g.vertices[2].push_back(0);

    cout<<"The first vertex of graph is "<<g.firstVertex()<<endl;
    cout<<"Checking for cyclic graph "<<g.isCyclic();
    return 0;
}