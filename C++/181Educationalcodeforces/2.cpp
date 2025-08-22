#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;

        if (a == 0 && b == 0) {
            cout << "0\n";
            continue;
        }

        if (a <= k && b <= k) {
            cout << "1\n";
            continue;
        }

        long long g = gcd(a, b);
        long long dx = a / g;
        long long dy = b / g;

        if (dx <= k && dy <= k) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}
