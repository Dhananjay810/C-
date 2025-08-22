#include <iostream>
using namespace std;

long long countBad(long long x) {
    long long res = 0;
    int primes[] = {2, 3, 5, 7};
    for (int mask = 1; mask < (1 << 4); ++mask) {
        long long lcm = 1;
        int bits = 0;
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                lcm *= primes[i];
                bits++;
            }
        }
        if (lcm > x) continue;
        if (bits % 2 == 1) res += x / lcm;
        else res -= x / lcm;
    }
    return res;
}

long long countGood(long long x) {
    if (x < 10) return 0;
    return x - countBad(x);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        if(l>10) cout << countGood(r) - countGood(l - 1) << "\n";
        else cout << countGood(r) - countGood(l - 1)-1 << "\n";
    }
    return 0;
}
