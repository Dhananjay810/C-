#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        int maxHeight = *max_element(h.begin(), h.end());
        vector<int> time(n, INT_MAX);
        queue<int> q;

        // Start from tower (k-1) at time 0
        time[k - 1] = 0;
        q.push(k - 1);

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            for (int i = 0; i < n; i++) {
                if (i == curr) continue;
                int t_next = time[curr] + abs(h[i] - h[curr]);
                if (t_next < h[i] && t_next < time[i]) {
                    time[i] = t_next;
                    q.push(i);
                }
            }
        }

        bool possible = false;
        for (int i = 0; i < n; i++) {
            if (h[i] == maxHeight && time[i] < h[i]) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
}