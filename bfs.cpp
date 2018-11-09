#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

class Graph
{
    int v;
    vector<int>*adj;
public:
    Graph(int v);

    void add_edge(int v,int w);

    void BFS(int s);
};

Graph::Graph(int v){
    this->v=v;
    adj=new vector<int>[v+1];
}

void Graph::add_edge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s){
    cout<<"source: "<<s<<endl;
    queue<int>q;
    q.push(s);

    int level[v+1];
    for(int i=0;i<v+1;i++) level[i]=-1;

    level[s]=0;
    while(!q.empty()){
        
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(auto i=0;i<adj[u].size();i++){
            if(level[adj[u][i]]==-1){
                level[adj[u][i]]=level[u]+1;
                q.push(adj[u][i]);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<v+1;i++){
        cout<<"node: "<<i<<" distantce: "<<level[i]<<endl;
    }
}

int main(){
    Graph g(10);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,6);
    g.add_edge(3,8);
    g.add_edge(3,7);
    g.add_edge(4,7);
    g.add_edge(6,10);
    g.add_edge(7,9);
    g.add_edge(9,10);
    g.add_edge(7,8);
    g.add_edge(8,5);
    g.add_edge(10,5);
    
    g.BFS(1);
    
}