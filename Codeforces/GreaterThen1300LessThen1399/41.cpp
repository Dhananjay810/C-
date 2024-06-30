#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s.size() % n != 0) {
        cout << -1;
        return 0;
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < s.size(); i += n) {
        for (int j = 1; j < n; ++j) {
            if (s[i] != s[i + j]) {
                cout << -1;
                return 0;
            }
        }
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s.size() / n; ++j) {
            result += s[i + j * n];
        }
    }

    cout << result;
    return 0;
}
