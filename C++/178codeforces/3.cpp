#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
long long n;

// Returns true if Alice wins from the current state
bool solve(int maskA, int maskB, unordered_map<long long, bool>& memo, bool aliceTurn = true) {
    long long state = ((long long)maskA << (n + 1)) | maskB;
    if (memo.count(state)) return memo[state];

    if (aliceTurn) {
        // Alice's turn
        bool canWin = false;
        if (__builtin_popcount(maskA) == 0) { // Alice has no cards, she loses
            return memo[state] = false;
        }
        for (int i = 1; i <= n; ++i) {
            if (maskA & (1 << i)) { // Alice has card i
                int newMaskA = maskA ^ (1 << i);
                // Try all Bob's responses
                bool bobMustWin = true;
                for (int j = 1; j <= n; ++j) {
                    if (maskB & (1 << j)) { // Bob has card j
                        int newMaskB = maskB ^ (1 << j);
                        bool beats = (i > j) || (i == 1 && j == n);
                        if (beats) {
                            // Alice takes both cards
                            if (!solve(newMaskA | (1 << i) | (1 << j), newMaskB, memo, false)) {
                                bobMustWin = false;
                            }
                        } else {
                            // Bob takes both cards
                            if (!solve(newMaskA, newMaskB | (1 << i) | (1 << j), memo, false)) {
                                bobMustWin = false;
                            }
                        }
                    }
                }
                if (bobMustWin) canWin = true;
            }
        }
        return memo[state] = canWin;
    } else {
        // Bob's turn
        bool canWin = true;
        if (__builtin_popcount(maskB) == 0) { // Bob has no cards, he loses
            return memo[state] = true; // Alice wins
        }
        for (int j = 1; j <= n; ++j) {
            if (maskB & (1 << j)) { // Bob has card j
                int newMaskB = maskB ^ (1 << j);
                // Simulate previous Alice's move to determine outcome
                // We assume Alice played some card i, and check if j beats it
                bool beats = false;
                for (int i = 1; i <= n; ++i) {
                    if ((maskA & (1 << i)) || (newMaskB & (1 << i))) {
                        beats |= !((i > j) || (i == 1 && j == n));
                    }
                }
                if (beats) {
                    // Bob takes both cards
                    if (solve(maskA, newMaskB | (1 << j), memo, true)) {
                        canWin = false;
                    }
                } else {
                    // Alice takes both cards
                    if (solve(maskA | (1 << j), newMaskB, memo, true)) {
                        canWin = false;
                    }
                }
            }
        }
        return memo[state] = canWin;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;

        // Initialize masks
        int maskA = 0, maskB = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') maskA |= (1 << (i + 1));
            else maskB |= (1 << (i + 1));
        }

        // Initialize memoization map
        unordered_map<long long, bool> memo;

        // Solve and output result
        cout << (solve(maskA, maskB, memo) ? "Alice" : "Bob") << '\n';
    }

    return 0;
}