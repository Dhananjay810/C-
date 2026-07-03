#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        ll ans = 0;

        for (int i = 0; i + 1 < n; i++) {
            int x = p[i];
            int y = p[i + 1];

            if (__gcd(x, y) == abs(x - y)) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}