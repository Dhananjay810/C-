#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest){
    graph[src].push_back(dest);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto x : graph[i]){
            cout<<x<<" , ";
        }
        cout<<endl;
    }
}

void g(){
    vector<int> indegree(v,0);
    for(int i=0; i<v; i++){
        indegree[i]=graph[i].size();
    }
    for(int i=0; i<v; i++) cout<<indegree[i]<<" ";
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
        add_edge(s,d); // Directed
    }
    // display();
    g();
}