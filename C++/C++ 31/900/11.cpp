#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> ans(n);

        for (int i = 0; i < n; i++) {
            cin >> ans[i];
            if (ans[i] == 1) ans[i] = 2;
        }

        for (int i = 1; i < n; i++) {
            while (ans[i] % ans[i - 1] == 0) {
                ans[i]++;
            }
        }

        for (auto x : ans) cout << x << " ";
        cout <<endl;
    }
}
