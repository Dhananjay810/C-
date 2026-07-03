#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;

        int L = n - k;

        vector<int> prefClose(n + 1, 0);
        vector<int> suffOpen(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefClose[i + 1] = prefClose[i] + (s[i] == ')');
        }

        for (int i = n - 1; i >= 0; i--) {
            suffOpen[i] = suffOpen[i + 1] + (s[i] == '(');
        }

        int bestPos = 0;
        int bestCnt = -1;

        for (int pos = 0; pos <= n; pos++) {
            int cur = prefClose[pos] + suffOpen[pos];
            if (cur > bestCnt) {
                bestCnt = cur;
                bestPos = pos;
            }
        }

        vector<int> keep(n, 0);

        for (int i = 0; i < bestPos; i++) {
            if (s[i] == ')') keep[i] = 1;
        }

        for (int i = bestPos; i < n; i++) {
            if (s[i] == '(') keep[i] = 1;
        }

        int curKeep = bestCnt;

        if (curKeep > L) {
            int extra = curKeep - L;

            for (int i = 0; i < n && extra; i++) {
                if (keep[i]) {
                    keep[i] = 0;
                    extra--;
                }
            }
        } else if (curKeep < L) {
            int need = L - curKeep;

            for (int i = 0; i < n && need; i++) {
                if (!keep[i]) {
                    keep[i] = 1;
                    need--;
                }
            }
        }

        string ans(n, '1'); // 1 = removed

        for (int i = 0; i < n; i++) {
            if (keep[i]) ans[i] = '0';
        }

        cout << ans << '\n';
    }

    return 0;
}