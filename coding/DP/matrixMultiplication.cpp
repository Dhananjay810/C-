#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> dp;

int f(int i, int j, vector<int>& v){
    if(i==j || i==j-1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];


    int ans=INT_MAX;
    for(int k=i+1; k<j; k++){
        ans=min(ans,f(i,k,v)+f(k,j,v)+v[i]*v[k]*v[j]);
    }
    return dp[i][j]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    dp.clear();
    dp.resize(1005, vector<int>(1000, -1));
    cout<<f(0,n-1,v);
}