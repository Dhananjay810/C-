#include<iostream>
#include<vector>
#include<climits>
#define mod 1000000007
using namespace std;

vector<int> c={1,2,3,4,5,6};
vector<long long> dp(1000006,-1);


long long f(int x,long long& sum){
    if(x==0) return 1;
    if(dp[x]!=-1) return dp[x];
    // long long sum=0;
    for(int i=0; i<6; i++){
        if(x-c[i]<0) break;
        sum = (sum % mod +f(x-c[i],sum) % mod) % mod;
        
    }
    return dp[x]=sum;
}

// long long fn(int x){
//     dp[0]=1;

//     for(int i=1; i<=x; i++){
//         long long sum=0;
//         for(int k=0; k<6; k++){
//             if(x-c[k]<0) break;
//             sum = (sum % mod +dp[i-c[k]] % mod) % mod;
//         }
//         dp[i]=sum%mod;
//     }
//     return dp[x];
// }

int main(){
    int n;
    cin>>n;
    long long sum=0;
    cout<<f(n,sum);
    // cout<<fn(n);
}