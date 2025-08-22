#include<iostream>
#include<vector>
#include<cstring>
# define ll long long int
using namespace std;


vector<int> a,b;    
ll dp[2005][2005][8];

int f(int i,int j,int k){
    if(i==a.size() || j==b.size()) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll ans=0;
    if(a[i]==b[j]) ans=1+f(i+1,j+1,k);
    else{
        if(k>0){
            ans=max(1+f(i+1,j+1,k-1),max(f(i+1,j,k),f(i,j+1,k)));
        }
        else{
            ans=max(f(i+1,j,k),f(i,j+1,k));
        }
    }
    return dp[i][j][k]=ans;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    a.resize(n);
    b.resize(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,k);
}