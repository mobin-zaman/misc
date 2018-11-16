#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define edge pair<int,int>

class Graph{
    vector<pair<int,edge>>G;   
    vector<pair<int,edge>>T;
    int *parent;
    int v;
    public:
    Graph(int v);
    void add_weighted_edge(int u,int v,int w);
    int find_set(int i);
    void union_set(int u,int v);
    void kruskal();
    void print();
};

Graph::Graph(int v){
    parent=new int[v];
    for(int i=0;i<v;i++) parent[i]=i;
}

void Graph::add_weighted_edge(int u,int v,int w){
    G.push_back(make_pair(w,edge(u,v)));
}

int Graph::find_set(int i){
    if(i==parent[i]) return i;
    else return find_set(parent[i]);
}

void Graph::union_set(int u,int v){
    parent[u]=parent[v];
}

void Graph::kruskal(){
    int  uRep, vRep;
    sort(G.begin(),G.end());
    for(int i=0; i<G.size();i++){
        uRep=find_set(G[i].second.first);
        vRep=find_set(G[i].second.second);
        if(uRep!=vRep){
            T.push_back(G[i]);
            union_set(uRep,vRep);
        }
    }
}

void Graph::print(){
    cout<<"edge :"<<" weight"<<endl;
    for(int i=0;i<T.size();i++){
        cout<<T[i].second.first<<" - "<<T[i].second.second <<" : "<<T[i].first;
        cout<<endl;
    }
}
int main() {
    Graph g(6);
    g.add_weighted_edge(0, 1, 4);
    g.add_weighted_edge(0, 2, 4);
    g.add_weighted_edge(1, 2, 2);
    g.add_weighted_edge(1, 0, 4);
    g.add_weighted_edge(2, 0, 4);
    g.add_weighted_edge(2, 1, 2);
    g.add_weighted_edge(2, 3, 3);
    g.add_weighted_edge(2, 5, 2);
    g.add_weighted_edge(2, 4, 4);
    g.add_weighted_edge(3, 2, 3);
    g.add_weighted_edge(3, 4, 3);
    g.add_weighted_edge(4, 2, 4);
    g.add_weighted_edge(4, 3, 3);
    g.add_weighted_edge(5, 2, 2);
    g.add_weighted_edge(5, 4, 3);
    g.kruskal();
    g.print();
    return 0;
}