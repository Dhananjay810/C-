#include<iostream>
#include<vector>
// #include<cstring>
#define ll long long int
using namespace std;

ll f(int i, int j, vector<ll>&v, vector<vector<ll>>& dp){
    if(i==j) return v[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(v[i]-f(i+1,j,v,dp),v[j]-f(i,j-1,v,dp));
}

int main(){
    int n;
    cin>>n;
    vector<ll> v(3005);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<vector<ll>> dp(3005,vector<ll>(3005,-1));
    // memset(dp,-1,sizeof dp);
    cout<<f(0,n-1,v,dp);
}