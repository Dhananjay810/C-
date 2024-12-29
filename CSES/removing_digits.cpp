#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> get_dig(int n){
    vector<int> v;
    while(n>0){
        if(n%10!=0) v.push_back(n%10);
        n=n/10;
    }
    return v;
}

int f(int n,vector<int>& dp){
    if(n==0) return 0;
    if(n<=9) return 1;

    vector<int> dig=get_dig(n);
    if(dp[n]!=-1) return dp[n];
    int result=INT_MAX;
    for(int i=0; i<dig.size(); i++){
        result=min(result,f(n-dig[i],dp));
    }
    return dp[n]=1+result;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+5,-1);
    cout<<f(n,dp);
}