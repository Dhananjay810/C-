#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


long long f(int n, vector<int>& v, int i,vector<long long>& dp){
    if(i==n-1) return 0;
    if(i==n-2) return abs(v[n-1]-v[n-2]);

    if(dp[i]!=-1) return dp[i];

    long long result=INT_MAX;

    result=min(abs(v[i+1]-v[i])+f(n,v,i+1,dp),abs(v[i+2]-v[i])+f(n,v,i+2,dp));

    return dp[i]=result;
}

int main(){
    int n;
    cin>>n;
    vector<long long> dp(n+1,-1);

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    cout<<f(n,v,0,dp);
}