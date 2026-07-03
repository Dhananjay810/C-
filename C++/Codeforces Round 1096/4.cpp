#include<bits/stdc++.h>
using namespace std;

bool isPal(int l, int r, vector<int>& a){
    while(l < r){
        if(a[l] != a[r]) return false;
        l++; r--;
    }
    return true;
}

int computeMex(int l, int r, vector<int>& a){
    unordered_set<int> s;
    for(int i = l; i <= r; i++) s.insert(a[i]);
    int mex = 0;
    while(s.count(mex)) mex++;
    return mex;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++) cin >> a[i];

        vector<int> first(n, -1), second(n, -1);
        for(int i = 0; i < 2*n; i++){
            if(first[a[i]] == -1) first[a[i]] = i;
            else second[a[i]] = i;
        }

        int ans = 1;
        for(int v = 0; v < n; v++){
            int l = first[v], r = second[v];
            if(isPal(l, r, a)){
                ans = max(ans, computeMex(l, r, a));
            }
        }

        cout << ans << "\n";
    }
}