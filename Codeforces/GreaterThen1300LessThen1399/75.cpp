#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int f(int len,vector<int>& v,vector<int>& dp){
    if(len==0) return 0;
    
    if(dp[len]!=-1) return dp[len];

    int ans=INT_MIN;
    for(int i=0; i<3; i++){
        if(len-v[i]<0) continue;
        ans=max(ans,1+f(len-v[i],v,dp));
    }
    return dp[len]=ans;
}

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    vector<int> dp(n+1,-1);

    vector<int> v(3);
    v[0]=a;
    v[1]=b;
    v[2]=c;

    cout<<f(n,v,dp);

}