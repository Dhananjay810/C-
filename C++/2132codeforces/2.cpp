#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> res;

        for (long long k = 1, p = 10; k <= 18; k++, p *= 10) {
            long long d = p + 1;  // divisor = 10^k + 1
            if (n % d == 0) {
                long long x = n / d;
                res.push_back(x);
            }
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else {
            sort(res.begin(), res.end());
            cout << res.size() << " ";
            for (auto x : res) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
