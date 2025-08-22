#include <iostream>
#include <cmath>
using namespace std;

long long nearestPowerOfThree(long long n) {
    if (n < 1) return 0;

    int exp = (int)(log(n) / log(3));
    long long power = pow(3, exp);
    while (power > n) power /= 3;
    while (power * 3 <= n) power *= 3;

    return power;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        long long y = n;

        while (y > 0) {
            long long d = nearestPowerOfThree(y);
            long long h = (long long)(log(d) / log(3) + 1e-9);

            // your calculation
            if (d == 1) h = 0;
            ans += pow(3, h + 1);
            if (h > 0) ans += h * pow(3, h - 1);

            y -= d;
        }

        cout << ans << "\n";
    }
}
