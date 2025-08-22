#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> S(n), T(n);
        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> T[i];
        }

        if (k == 0) {
            if (S == T) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        vector<long long> repS, repT;
        long long modulus = 2 * k;

        for (int i = 0; i < n; i++) {
            long long r = S[i] % modulus;
            long long candidate1 = min(r, modulus - r);
            long long candidate2 = k - candidate1;
            long long rep = min(candidate1, candidate2);
            repS.push_back(rep);
        }

        for (int i = 0; i < n; i++) {
            long long r = T[i] % modulus;
            long long candidate1 = min(r, modulus - r);
            long long candidate2 = k - candidate1;
            long long rep = min(candidate1, candidate2);
            repT.push_back(rep);
        }

        sort(repS.begin(), repS.end());
        sort(repT.begin(), repT.end());

        if (repS == repT) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}