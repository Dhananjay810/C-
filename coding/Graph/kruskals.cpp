#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int find(vector<int> &par, int a){
    if(par[a]==a) return a;
    return par[a]=find(par,par[a]);
}

void Union(vector<int> &par, vector<int> &rank, int a, int b){
    a=find(par,a);
    b=find(par,b);

    if(a==b) return;

    if(rank[a]<=rank[b]){
        rank[b]++;
        par[a]=b;
    }
    else{
        rank[a]++;
        par[b]=a;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt<e2.wt;
}

ll kruskals(vector<Edge> &input, int n, int e){
    sort(input.begin(),input.end(),cmp);
    vector<int> par(n+1);
    vector<int> rank(n+1,1);
    for(int i=0; i<=n; i++) par[i]=i;

    int ans=0;
    int edgecount=0;
    int i=0;
    while(edgecount<n-1 && i<input.size()){
        Edge e=input[i];
        int srcpar=find(par,e.src);
        int destpar=find(par,e.dest);

        if(srcpar != destpar){
                Union(par,rank,srcpar,destpar);
                ans+=e.wt;
                edgecount++;
        }
        i++;
    }
    return ans;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i=0; i<e; i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v,n,e);
}