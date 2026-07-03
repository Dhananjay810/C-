#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long sum = 0;
        long long mn = (long long)4e18;

        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;

            sum += x;
            mn = min(mn, sum / i);

            cout << mn<<" ";
        }
        cout << '\n';
    }
}