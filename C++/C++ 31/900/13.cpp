#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int seg = 0;
        bool in = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                if (!in) {
                    seg++;
                    in = true;
                }
            } else {
                in = false;
            }
        }

        cout << min(seg, 2) << '\n';
    }

    return 0;
}