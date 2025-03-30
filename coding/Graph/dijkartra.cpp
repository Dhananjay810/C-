#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<climits>
#define pp pair<int,int>
using namespace std;
int v;
vector<list<pp>> graph;

void build(int src, int dest, int wt){
    graph[src].push_back({dest,wt});
    graph[dest].push_back({src,wt});
}

unordered_map<int,int> dijastra(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> via(n+1);
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) mp[i]=INT_MAX;
    mp[src]=0;
    pq.push({0,src});
    while(pq.size()>0){
        pp curr=pq.top();
        if(vis.find(curr.second)!=vis.end()){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neig : graph[curr.second]){
            if(vis.find(neig.first)==vis.end() && mp[neig.first]>mp[curr.second]+neig.second){
                pq.push({mp[curr.second]+neig.second,neig.first});
                via[neig.first]=curr.second;
                mp[neig.first]=mp[curr.second]+neig.second;
            }
        }
    }
    return mp;
}

int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n,list<pp>());
    while(m--){
        int s,d,w;
        cin>>s>>d>>w;
        build(s,d,w);
    }
    cout<<"esrfs";
    int src;
    cin>>src;
    unordered_map<int,int> ans=dijastra(src, n);
    // for(auto x :ans){
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
    int dest;
    cin>>dest;
    cout<<ans[dest];
}