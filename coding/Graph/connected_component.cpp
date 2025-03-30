#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int node, unordered_set<int>& visi){
        visi.insert(node);
        for(auto neig : graph[node]){
            if(visi.find(neig)==visi.end()){
                dfs(neig, visi);
            }
        }
}

int conn_comp(){
    int ans=0;
    unordered_set<int> visi;
    for(int i=0; i<v; i++){
        if(visi.find(i)==visi.end()){
            ans++;
            dfs(i,visi);
        }
    }
    return ans;
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
    cout<<conn_comp();
}