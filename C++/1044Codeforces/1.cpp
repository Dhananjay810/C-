#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> seen;
        bool duplicate = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (seen.find(a[i]) != seen.end()) {
                duplicate = true;
            }
            seen.insert(a[i]);
        }
        if (duplicate) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}