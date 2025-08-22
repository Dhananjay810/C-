#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

bool bfs(int src, unordered_set<int>& vis){
    vis.insert(src);
    queue<int> q;
    q.push(src);
    while(q.size()>0){
        int u=q.front();
        q.pop();
        for(auto neig : graph[u]){
            if(vis.find(neig)!=vis.end() && neig!=u){
                // cout<<u<<" "<<neig<<endl;
                return true;
            }
            else{
                q.push(neig);
                vis.insert(neig);
            }
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> vis;
    for(int i=0; i<v; i++){
        if(!vis.count(i)){
            bool res=bfs(i,vis);
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
        add_edge(s,d); // bidirected
        // add_edge(s,d,false); // Directed
    }
    cout<<has_cycle();
}