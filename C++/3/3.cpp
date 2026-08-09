#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> can(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            can[x] = 1;
        }

        const long long NEG = -(1LL << 60);

        long long dp0 = 0;     // even flips
        long long dp1 = NEG;   // odd flips impossible initially

        for (int i = n; i >= 1; i--) {

            long long ndp0 = NEG, ndp1 = NEG;

            // do not flip at i
            ndp0 = max(ndp0, dp0 + a[i]);
            if (dp1 != NEG)
                ndp1 = max(ndp1, dp1 - a[i]);

            // flip at i (if possible)
            if (can[i]) {
                if (dp0 != NEG)
                    ndp1 = max(ndp1, dp0 - a[i]);

                if (dp1 != NEG)
                    ndp0 = max(ndp0, dp1 + a[i]);
            }

            dp0 = ndp0;
            dp1 = ndp1;
        }

        cout << dp0 << "\n";
    }

    return 0;
}