#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int bad_pairs = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            bad_pairs++;
        }
    }
    if (bad_pairs <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}