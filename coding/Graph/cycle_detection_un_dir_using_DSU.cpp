#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>& parent, int x){
    // TC o(log*n)
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}

bool unin(vector<int>& parent, vector<int>& rank, int a, int b){
    // TC o(log*n)
    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return true;
    if(rank[a]<=rank[b]){
        rank[b]++;
        parent[a]=b;
    }
    else{
        rank[a]++;
        parent[b]=a;
    }
    return false;
}

int main(){
    int n,m;
    // n->element, m->queries
    cin>>n>>m;
    vector<int> parent(n+1); // 0 indexing
    vector<int> rank(n+1,0);
    for(int i=0; i<=n; i++){
        parent[i]=i;
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        bool b=unin(parent,rank,x,y);
        if(b==true){
            cout<<"Cycle detected"<<endl;
            return 0;
        }
    }
}