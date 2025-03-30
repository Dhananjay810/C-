#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;
vector<vector<int>> ans;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int curr, int end,vector<int>& path){
    if(curr==end){
        path.push_back(curr);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neig : graph[curr]){
        if(visited.find(neig)==visited.end()){
            dfs(neig,end,path);
        }
    }
    visited.erase(curr);
    path.pop_back();
    return;
}

void allpath(int src,  int dest){
    vector<int> v;
    dfs(src,dest,v);
}


int main(){
    cin>>v;
    int e;
    visited.clear();
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d); // bidirected
        // add_edge(s,d,false); // Directed
    }
    int x,y;
    cin>>x>>y;
    allpath(x,y);
    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

}