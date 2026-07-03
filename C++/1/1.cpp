#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k >= n) {
            cout << n << '\n';
            continue;
        }

        long long rem = n;
        long long ans = 0;

        for (long long cost = 1; cost <= rem; cost <<= 1) {
            long long take = min(k, rem / cost);
            ans += take;
            rem -= take * cost;
        }

        cout << ans << '\n';
    }

    return 0;
}