#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

bool dfs(int curr, int end){
    if(curr==end) return true;
    visited.insert(curr);
    for(auto neig : graph[curr]){
        if(visited.find(neig)==visited.end()){
            bool result=dfs(neig,end);
            if(result==true) return true;
        }
    }
    return false;
}

bool any_path(int start, int end){
    return dfs(start,end);
}


int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d); // bidirected
        // add_edge(s,d,false); // Directed
    }
    int st,ed;
    cin>>st>>ed;
    cout<<any_path(st,ed);
}