#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> c;
vector<int> dp(1000006,-2);


int f(int x){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];
    int result=INT_MAX;
    for(int i=0; i<c.size(); i++){
        if(x-c[i]<0) continue;
        result=min(result,f(x-c[i]));
    }
    if(result==INT_MAX) return dp[x]=INT_MAX;
    return  dp[x]=1+result;
}
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        c.push_back(num);
    }
    int ans=f(x);
    if(ans==INT_MAX) cout<<"-1";
    else cout<<ans;
}