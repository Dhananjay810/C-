#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> freq(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x <= n) {
                freq[x]++;
            }
        }
        
        int mex = 0;
        while (mex < k && freq[mex] > 0) {
            mex++;
        }
        if (mex == k) {
            mex = k - 1;
        }
        
        cout << mex << "\n";
    }
    
    return 0;
}