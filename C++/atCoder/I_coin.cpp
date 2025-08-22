#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;

double dp[3005][3005];

double f(vector<double>& v, int i, int x){
    if(x==0) return 1;
    if(i==-1) return 0;
    if(dp[i][x]>-0.9) return dp[i][x];
    return dp[i][x]=f(v,i-1,x-1)*v[i]+f(v,i-1,x)*(1-v[i]);

}

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<double> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<fixed<<setprecision(9)<<f(v,n-1,(n+1)/2);
}