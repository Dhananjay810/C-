#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

bool isBeautiful(const vector<int>& v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        if (abs(v[i] - v[i+1]) <= 1) {
            return true;
        }
    }
    return false;
}

int minOperations(vector<int>& a, int operations, unordered_map<string, int>& memo) {
    string key;
    for (int num : a) {
        key += to_string(num) + ",";
    }
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    if (isBeautiful(a)) {
        return operations;
    }
    if (a.size() < 2) {
        return -1;
    }
    int minOps = INT_MAX;
    for (int i = 0; i < a.size() - 1; ++i) {
        int min_val = min(a[i], a[i+1]);
        int max_val = max(a[i], a[i+1]);
        for (int x = min_val; x <= max_val; ++x) {
            vector<int> newA = a;
            newA.erase(newA.begin() + i, newA.begin() + i + 2);
            newA.insert(newA.begin() + i, x);
            int res = minOperations(newA, operations + 1, memo);
            if (res != -1) {
                minOps = min(minOps, res);
            }
        }
    }
    memo[key] = (minOps == INT_MAX) ? -1 : minOps;
    return memo[key];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        unordered_map<string, int> memo;
        cout << minOperations(a, 0, memo) << endl;
    }
    return 0;
}