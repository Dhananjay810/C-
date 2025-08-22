#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ull long long
const ull MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), q(n);
        vector<ull> a(n), b(n);

        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> q[i];

        for (int i = 0; i < n; ++i) {
            a[i] = (1LL << p[i]) % MOD;
            b[i] = (1LL << q[i]) % MOD;
        }

        vector<ull> r(n);

        for (int i = 0; i < n; ++i) {
            ull max_val = 0;
            for (int j = 0; j <= i; ++j) {
                ull val = (a[j] + b[i - j]) % MOD;
                if (val > max_val) max_val = val;
            }
            r[i] = max_val;
        }

        for (int i = 0; i < n; ++i) {
            cout << r[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
