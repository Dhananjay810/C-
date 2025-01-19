#include<iostream>
#include<vector>
#include<cstring>
#define ld long long double
using namespace std;

ld dp[105][105][105];

ld f(int r, int s, int p){
    ld total=r*s+s*p+p*r;

    if(dp[r][s][p]>-0.9) return d[r][s][p];

    ld ans=0.0;
    ans+=f(r,s-1,p)*((r*s)/total);
    ans+=f(r-1,s,p)*((r*p)/total);
    ans+=f(r,s,p-1)*((s*p)/total);

    return dp[r][s][p]=ans;

}

int main(){
    int r,s,p;
    cin>>r>>s>>p;
    memset(dp,-1,sizeof dp);
    cout<<f(r,s,p);
}