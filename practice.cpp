#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph;
void add(int src, int dest){
    graph[src].push_back(dest);
}
int main(){
    int v;
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int src,dest;
        cin>>src>>dest;
        add(src,dest);
    }
    vector<int> out(v,0);
    for(int i=0; i<v; i++){
        for(auto neig : graph[i]){
            out[i]++;
        }
    }
    for(int i=0; i<v; i++) cout<<i<<" "<<out[i]<<endl;
}