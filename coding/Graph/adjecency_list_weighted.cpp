#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<pair<int,int>>> graph;
int v;
void add_edge(int src, int dest, int weight, bool bi_dir=true){
    graph[src].push_back({dest,weight});
    if(bi_dir) graph[dest].push_back({src,weight});
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto x : graph[i]){
            cout<<"("<<x.first<<","<<x.second<<")"<<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<pair<int,int>>());
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        // add_edge(s,d,w); // bidirected
        add_edge(s,d,w,false); // Directed
    }
    display();
}