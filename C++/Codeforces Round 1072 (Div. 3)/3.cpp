#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        if (k > n) {
            cout << -1 << "\n";
            continue;
        }
        
        if (k == n) {
            cout << 0 << "\n";
            continue;
        }
        
        long long ans = -1;
        for (long long i = 1; i <= 60; i++) {
            long long L = n >> i;
            if (L == 0) break;
            long long R = (n + (1LL << i) - 1) >> i;
            
            if (L <= k && k <= R) {
                ans = i;
                break;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}