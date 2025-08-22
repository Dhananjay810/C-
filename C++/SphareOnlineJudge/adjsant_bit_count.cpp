#include<iostream>
#include<vector>
#include<cstring>
#define ll long long int
using namespace std;

ll dp[105][105][2];

ll f(int n, int k, int last){
    if(n==0) return 0;
    if(n==1){
        if(k==0) return 1;
        else return 0;
    }
    if(dp[n][k][last]!=-1) return dp[n][k][last];
    if(last==1){
        return dp[n][k][last]=f(n-1,k-1,1)+f(n-1,k,0);
    }
    else{
        return dp[n][k][last]=f(n-1,k,1)+f(n-1,k,0);
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        ll a,n,k;
        cin>>a>>n>>k;
        memset(dp,-1,sizeof dp);
        ll ans=f(n,k,0)+f(n,k,1);
        cout<<a<<" "<<ans<<endl;
    }
}