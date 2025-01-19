#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int f(int i, int j, vector<int>& v,vector<vector<int>>& dp){
    int n=v.size();
    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int on=0,ze=0;

    for(int a=i; a<=j; a++){
        if(v[a]==1) on++;
        else ze++;
    }
    int xx=ze-on;
    // maxfi=max(maxfi,xx);

    int maxfi1=f(i+1,j,v,dp);
    int maxfi2=f(i,j-1,v,dp);

    return dp[i][j]=max(xx,max(maxfi1,maxfi2));

}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int one=0;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
        if(num==1) one++;
    }

    if(one==n){
        cout<<n-1;
        return 0;
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

    
    cout<<one+f(0,n-1,v,dp);
}