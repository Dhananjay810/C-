#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int ans = 1, cur = 1;
        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] == v[i - 1] + 1) {
                cur++;
            } else {
                cur = 1;
            }
            ans = max(ans, cur);
        }
        if (v.size() == 1) ans = 1;

        cout << ans << "\n";
    }
    return 0;
}
