#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<bool> left_has(n, false);
        vector<bool> right_has(n, false);
        vector<int> seen(26, 0);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (seen[s[i] - 'a'] > 0) {
                    left_has[i] = true;
                }
            }
            seen[s[i] - 'a']++;
        }

        vector<int> seen2(26, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                if (seen2[s[i] - 'a'] > 0) {
                    right_has[i] = true;
                }
            }
            seen2[s[i] - 'a']++;
        }

        bool found_step1 = false;
        for (int i = 1; i <= n - 2; i++) {
            if (left_has[i] || right_has[i]) {
                found_step1 = true;
                break;
            }
        }

        if (found_step1) {
            cout << "Yes\n";
            continue;
        }

        if (n < 4) {
            cout << "No\n";
            continue;
        }

        map<pair<char, char>, vector<int>> bigram_occ;
        for (int i = 0; i < n - 1; i++) {
            pair<char, char> p = make_pair(s[i], s[i + 1]);
            bigram_occ[p].push_back(i);
        }

        bool found_step3 = false;
        for (const auto& kv : bigram_occ) {
            const vector<int>& v = kv.second;
            if (v.size() < 2) continue;

            int min_index = v[0];
            int max_index = v[0];
            for (int idx : v) {
                if (idx < min_index) min_index = idx;
                if (idx > max_index) max_index = idx;
            }

            for (int idx : v) {
                if (idx >= 1 && idx <= n - 3) {
                    if (min_index <= idx - 2 || max_index >= idx + 2) {
                        found_step3 = true;
                        break;
                    }
                }
            }
            if (found_step3) break;
        }

        if (found_step3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}