#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        
        vector<bool> validA(n, true);
        for (int d = 0; d < n; d++) {
            for (int t = 0; t < n; t++) {
                if (a[t] >= b[(t + d) % n]) {
                    validA[d] = false;
                    break;
                }
            }
        }
        vector<bool> validC(n, true);
        for (int d = 0; d < n; d++) {
            for (int t = 0; t < n; t++) {
                if (b[t] >= c[(t + d) % n]) {
                    validC[d] = false;
                    break;
                }
            }
        }
        
        long long countA = 0, countC = 0;
        for (int d = 0; d < n; d++) {
            if (validA[d]) countA++;
            if (validC[d]) countC++;
        }
        
        long long ans = n * countA * countC;
        cout << ans <<endl;
    }
    
    return 0;
}