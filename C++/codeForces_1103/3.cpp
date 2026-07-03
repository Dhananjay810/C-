#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    
    if (x == 1) return abs(a - b);
    
    // List all possible values by repeated division
    ll ans = abs(a - b); // Only increments
    
    // Compute division sequences
    ll cur_a = a, cur_b = b;
    int steps_a = 0, steps_b = 0;
    
    while (true) {
        steps_a = 0;
        cur_a = a;
        while (cur_a > 0) {
            steps_b = 0;
            cur_b = b;
            while (cur_b > 0) {
                // try common target t
                ll t = max(cur_a, cur_b);
                ans = min(ans, steps_a + steps_b + (t - cur_a) + (t - cur_b));
                
                // next b value
                if (cur_b / x <= 0) break;
                cur_b = cur_b / x;
                steps_b++;
            }
            if (cur_a / x <= 0) break;
            cur_a = cur_a / x;
            steps_a++;
        }
        break; // single pass with a divisions, b divisions covers all
    }
    
    // Also try t = 0? cost infinite if a or b > 0 can't reach 0 without division if a,b>0, and if both 0 cost 0.
    if (a == 0 && b == 0) return 0;
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}