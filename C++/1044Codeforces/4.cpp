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
        vector<long long> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        long long ans = h[n-1];
        for (int i = 0; i < n-1; i++) {
            ans += max(0LL, h[i] - h[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}