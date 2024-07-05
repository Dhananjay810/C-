#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> l(m);
    for (int i = 0; i < m; i++) cin >> l[i];

    vector<int> distinctCount(n);
    unordered_set<int> seen;
    for (int i = n - 1; i >= 0; i--) {
        seen.insert(a[i]);
        distinctCount[i] = seen.size();
    }
    for (int i = 0; i < m; i++) {
        int idx = l[i] - 1;
        cout << distinctCount[idx] << endl;
    }

    return 0;
}
