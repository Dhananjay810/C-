#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;

vector<list<int>> graph;
unordered_set<int> vis;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

bool dfs_conn_graph(int src){
    vis.insert(src);
    for(auto neig : graph[src]){
        if(vis.find(neig)!=vis.end() && neig!=src) return true;
        else{
            bool b=dfs_conn_graph(neig);
            if(b==true) return true;
        }
    }
    return false;
}

bool dfs(int src, int par, unordered_set<int>& vis){
    vis.insert(src);
    for(auto neig : graph[src]){
        if(vis.find(neig)!=vis.end() && neig!=par){
            return true;
        }
        else{
            bool b=dfs(neig,src,vis);
            if(b==true) return true;
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> vis;
    for(int i=0; i<v; i++){
        if(!vis.count(i)){
            bool res=dfs(i,-1,vis);
            if(res==true) return true;
        }
    }
    return false;
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int s,d;
        cin>>s>>d;
        // add_edge(s,d); // bidirected
        add_edge(s,d,false); // Directed
    }
    cout<<has_cycle();
    // display();
}