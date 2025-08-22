#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int known_x = -1;
        bool consistent = true;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                int x = a[i] + b[i];
                if (known_x == -1) {
                    known_x = x;
                } else if (x != known_x) {
                    consistent = false;
                    break;
                }
            }
        }

        if (!consistent) {
            cout << 0 << endl;
            continue;
        }

        if (known_x != -1) {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    int bi = known_x - a[i];
                    if (bi < 0 || bi > k) {
                        valid = false;
                        break;
                    }
                }
            }
            cout << (valid ? 1 : 0) << endl;
        } else {
            int low = 0, high = k + a[0];
            for (int i = 0; i < n; i++) {
                low = max(low, a[i]);
                high = min(high, a[i] + k);
            }
            int possible_x = high - low + 1;
            cout << (possible_x > 0 ? possible_x : 0) << endl;
        }
    }
    return 0;
}
