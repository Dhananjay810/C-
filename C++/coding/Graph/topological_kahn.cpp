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

void topoBFS(){
    // Kahn's Algorithm

    vector<int> indegree(v,0);
    for(int i=0; i<v; i++){
        for(auto neig : graph[i]){
            indegree[neig]++;
        }
    }

    queue<int> qu;
    unordered_set<int> visited;

    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            qu.push(i);
            visited.insert(i);
        }
    }

    while(qu.size()>0){
        int a=qu.front();
        qu.pop();
        cout<<a<<" ";
        for(auto neig : graph[a]){
            if(visited.find(neig)==visited.end()){
                indegree[neig]--;
                if(indegree[neig]==0){
                    qu.push(neig);
                    visited.insert(neig);
                }
            }
        }
    }

}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false); // Directed
    }
    topoBFS();
}