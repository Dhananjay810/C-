#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> div6, others;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 6 == 0) div6.push_back(a[i]);
            else others.push_back(a[i]);
        }
        for (auto x : div6) cout << x << " ";
        for (auto x : others) cout << x << " ";
        cout <<endl;
    }

    return 0;
}