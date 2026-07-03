#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        bool ok = true;

        for (int r = 0; r < k; r++) {
            int cnt = 0;

            for (int i = r; i < n; i += k) {
                if (s[i] == '1') cnt++;
            }

            if (cnt % 2) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}