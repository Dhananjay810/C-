#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    unordered_map<int, int> m1;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        m1[i] = num;
    }

    // If start and target are the same, no moves are required
    if (s == t) {
        cout << "0";
        return 0;
    }

    // To detect cycles and ensure we do not loop infinitely
    unordered_map<int, bool> visited;
    int curIdx = s;
    int moves = 0;

    while (true) {
        if (visited[curIdx]) {
            // Cycle detected, not possible to reach the target
            cout << "-1";
            return 0;
        }

        visited[curIdx] = true;
        curIdx = m1[curIdx];
        moves++;

        if (curIdx == t) {
            cout << moves;
            return 0;
        }
    }
}
