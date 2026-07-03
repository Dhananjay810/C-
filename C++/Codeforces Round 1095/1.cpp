#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        long long sumNonOne = 0;
        int lastNonOne = -1;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > 1) {
                sumNonOne = (sumNonOne + a[i]) % MOD;
                lastNonOne = i;
            }
        }

        long long ans = 0;

        // Case 1: all elements are 1
        if (lastNonOne == -1) {
            ans = 1;
        } 
        else {
            ans = sumNonOne;
            if (lastNonOne < n) {
                ans = (ans + 1) % MOD;
            }
        }

        cout << ans % MOD << "\n";
    }

    return 0;
}