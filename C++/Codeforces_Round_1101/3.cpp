#include <bits/stdc++.h>
using namespace std;

int S;

int f(int i, string &lin, int empty, int occupied, int n, vector<vector<vector<int>>> &dp){
    if(i == (int)lin.size()) return 0;

    if(dp[i][empty][occupied] != -1) return dp[i][empty][occupied];

    int ans = f(i + 1, lin, empty, occupied, n, dp);

    int opened = n - empty;
    int free_nonempty = opened * S - occupied;
    int total_free = n * S - occupied;

    if(total_free == 0) return dp[i][empty][occupied]=ans;

    if(lin[i] == 'I'){
        if(empty > 0){
            ans = max(ans,1 + f(i + 1, lin, empty - 1, occupied + 1, n, dp));
        }
    }
    else if(lin[i] == 'E'){
        if(free_nonempty > 0){
            ans = max(ans,1 + f(i + 1, lin, empty, occupied + 1, n,dp));
        }
    }
    else{
        if(empty > 0){
            ans = max(ans,1 + f(i + 1, lin, empty - 1, occupied + 1, n,dp));
        }
        if(free_nonempty > 0){
            ans = max(ans,1 + f(i + 1, lin, empty, occupied + 1, n,dp));
        }
    }
    return dp[i][empty][occupied] = ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x >> S;

        string lin;
        cin >> lin;
        vector<vector<vector<int>>> dp(lin.size()+5,(vector<vector<int>>(x+5,vector<int>(S*x+5,-1))));

        cout << f(0, lin, x, 0, x,dp) << '\n';
    }
}