#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n), b(n);
        int sumA = 0, sumB = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sumA += a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sumB += b[i];
        }

        const int INF = 1e9;
        int ans = INF;
        bool ok = true;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                ok = false;
                break;
            }
            cost += a[i] - b[i];
        }

        if (ok)
            ans = cost;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool possible = (sumA >= sumB);

        for (int i = 0; i < n && possible; i++) {
            if (a[i] < b[i])
                possible = false;
        }

        if (possible)
            ans = min(ans, c + (sumA - sumB));

        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}