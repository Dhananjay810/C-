#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s, t;
        cin >> s >> t;

        int j = 0;
        bool possible = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                if (j < t.size()) {
                    s[i] = t[j];
                    j++;
                } else {
                    s[i] = 'a';
                }
            } else if (j < t.size() && s[i] == t[j]) {
                j++;
            }
        }

        if (j < t.size()) {
            possible = false;
        }

        if (possible) {
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}