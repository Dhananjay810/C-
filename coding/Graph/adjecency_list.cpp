#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
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
    display();
}