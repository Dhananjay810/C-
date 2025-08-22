#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int help(int n){
//     if(n==1) return 0;
//     if(n%2==0 && n%3==0){
//         return 1+min(min(help(n/2),help(n/3)),help(n-1));
//     }
//     else if(n%2==0){
//         return 1+min(help(n/2),help(n-1));
//     }
//     else if(n%3==0) return 1+min(help(n/3),help(n-1));
//     else return 1+help(n-1);
// }

int helpDP(int n, vector<int>& dp){
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    if(n%2==0 && n%3==0){
        return dp[n]=1+min(min(helpDP(n/2,dp),helpDP(n/3,dp)),helpDP(n-1,dp));
    }
    else if(n%2==0){
        return dp[n]=1+min(helpDP(n/2,dp),helpDP(n-1,dp));
    }
    else if(n%3==0) return dp[n]=1+min(helpDP(n/3,dp),helpDP(n-1,dp));
    else return dp[n]=1+helpDP(n-1,dp);
}

int main(){
    int n;
    cin>>n;
    int f;
    vector<int> dp(n+1,-1);
    // if(n%2==0 && n%3==0){
    //     f=1+min(min(help(n/2),help(n/3)),help(n-1));
    // }
    // else if(n%2==0){
    //     f=1+min(help(n/2),help(n-1));
    // }
    // else if(n%3==0) f=1+min(help(n-1),help(n/3));
    // else f=1+help(n-1);

    // if(n%2==0 && n%3==0){
    //     f=1+min(min(helpDP(n/2,dp),helpDP(n/3,dp)),helpDP(n-1,dp));
    // }
    // else if(n%2==0){
    //     f=1+min(helpDP(n/2,dp),helpDP(n-1,dp));
    // }
    // else if(n%3==0) f=1+min(helpDP(n-1,dp),helpDP(n/3,dp));
    // else f=1+helpDP(n-1,dp);

    vector<int> dpp(n+5,0);
    dpp[0]=0;
    dpp[1]=0;
    dpp[2]=1;
    dpp[3]=1;
    if(n<=3){
        cout<<1;
        return 0;
    }
    for(int i=4; i<=n; i++){
        if(i%2==0 && i%3==0){
            dpp[i]=1+min(min(dpp[i-1],dpp[i/2]),dpp[i/3]);
        }
        else if(i%2==0){
            dpp[i]=1+min(dpp[i/2],dpp[i-1]);
        }
        else if(i%3==0){
            dpp[i]=1+min(dpp[i/3],dpp[i-1]);
        }
        else{
            dpp[i]=1+dpp[i-1]; 
        }
    }
    cout<<dpp[n];

    // cout<<f;
}