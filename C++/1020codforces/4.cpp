#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        // Check if we can collect m flowers without inserting any
        int collected = 0;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] >= b[j]) {
                collected++;
                j++;
            }
            i++;
        }
        if (collected == m) {
            cout << 0 << '\n';
            continue;
        }
        // The minimal k is the largest b[j] that wasn't collected
        cout << b[collected] << '\n';
    }
    return 0;
}