#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<long long>> v(m, vector<long long>(3));
    for (int i = 0; i < m; i++) {
        long long g;
        cin >> g;
        v[i][0] = g;
        if (g == 1) {
            cin >> v[i][1] >> v[i][2];
        } else {
            cin >> v[i][1];
        }
    }

    long long addSum = 0; // To keep track of the added value for type 2 operations

    for (int i = 0; i < m; i++) {
        if (v[i][0] == 1) {
            a[v[i][1] - 1] = v[i][2] - addSum; // Adjust the set value by subtracting addSum
        } else if (v[i][0] == 2) {
            addSum += v[i][1];
        } else if (v[i][0] == 3) {
            cout << a[v[i][1] - 1] + addSum << endl; // Print the element adjusted by addSum
        }
    }

    return 0;
}
