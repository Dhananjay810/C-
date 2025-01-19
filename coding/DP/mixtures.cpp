#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> dp(105,vector<int>(105,-1));

int g(vector<int>& c, int i, int j){
    int res=0;
    for(int k=i; k<=j; k++){
        res=(res%100+c[k]%100)%100;
    }
    return res;
}

int f(int i, int j, vector<int>& colors){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;

    for(int k=i; k<j; k++){
        ans=min(ans,f(i,k,colors)+f(k+1,j,colors)+g(colors,i,k)*g(colors,k+1,j));
    }
    return dp[i][j]=ans;
}

int main(){
    int n;
    while(cin>>n){
        vector<int> co;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            co.push_back(num);
        }
        cout<<f(0,n-1,co)<<endl;
        co.clear();
    }
}