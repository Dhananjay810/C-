#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long total = a + b + c;
        if (total % 3 != 0) {
            cout << "NO" << endl;
        } else {
            long long k = total / 3;
            if (k >= a && k >= b && k <= c) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}