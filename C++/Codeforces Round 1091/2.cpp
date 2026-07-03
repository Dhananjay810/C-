#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int solve(vector<int>& a, int p) {
    int n = a.size();
    int x = a[p];

    vector<int> bad(n);
    for (int i = 0; i < n; i++) {
        bad[i] = (a[i] != x);
    }

    int L = 0, R = 0;
    for (int i = 0; i < p; ) {
        if (bad[i]) {
            L++;
            while (i < p && bad[i]) i++;
        } else i++;
    }
    for (int i = p + 1; i < n; ) {
        if (bad[i]) {
            R++;
            while (i < n && bad[i]) i++;
        } else i++;
    }

    return 2 * max(L, R);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int kk;
        cin>>k;

        int ans=solve(v, k);
        cout<<ans<<endl;

    }
}