#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
#include<climits>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src,vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    q.push(src);
    while(q.size()>0){
        int curr=q.front();
        q.pop();
        for(auto neig : graph[curr]){
            if(visited.find(neig)==visited.end()){
                q.push(neig);
                visited.insert(neig);
                dist[neig]=dist[curr]+1;
            }
        }
    }
}

// bool any_path(int start, int end){
//     return dfs(start,end);
// }


int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    visited.clear();
    vector<int> dist;
    while(e--){
        int s,d;
        cin>>s>>d;
        // add_edge(s,d); // bidirected
        add_edge(s,d,false); // Directed
    }
    int st;
    cin>>st;
    // cout<<any_path(st,ed);
    bfs(st,dist);
    for(int i=0; i<dist.size(); i++) cout<<dist[i]<<" ";
}