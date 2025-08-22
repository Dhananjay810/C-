#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ans = 0;
        while (true) {
            bool step1Done = false;
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    a[i]--;
                    step1Done = true;
                    break;
                }
            }

            if (!step1Done) break;
            for (int i = 0; i < n; i++) {
                if (a[i] < b[i]) {
                    a[i]++;
                    break;
                }
            }

            ans++;
        }

        cout << ans+1 << "\n";
    }

    return 0;
}
