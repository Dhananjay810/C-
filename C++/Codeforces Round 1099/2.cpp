#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                ok = false;
                break;
            }
        }

        if (ok==true) {
            cout << "YES\n";
            continue;
        }

        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);

        int x = 0;
        vis1[0] = true;

        for (int i = 1; i < n; i++) {
            if (v[i] >= v[x]) {
                vis1[i] = true;
                x = i;
            }
        }

        int y = -1;

        for (int i = 0; i < n; i++) {
            if (!vis1[i]) {
                y = i;
                break;
            }
        }
        if (y == -1) {
            cout << "YES\n";
            continue;
        }

        vis2[y] = true;
        for (int i = y + 1; i < n; i++) {
            if (!vis1[i] && v[i] >= v[y]) {
                vis2[i] = true;
                y = i;
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (vis1[i] == false && vis2[i] == false) {
                flag = true;
                cout << "NO\n";
                break;
            }
        }

        if (flag) continue;
        int maxa=INT_MIN;
        int nemaxa=-1;
        for(int i=0; i<n; i++){
            if(vis1[i]==true) nemaxa=v[i];
            maxa=max(maxa,nemaxa-v[i]);
        }
        for (int i = 0; i < n; i++) {
            if (vis2[i]) {
                v[i] = v[i] + maxa;
            }
        }
        // for(int i=0; i<n; i++) cout<<v[i]<<" ";
        // cout<<"\n";
        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                flag = true;
                cout << "NO\n";
                break;
            }
        }

        if (flag == false) cout << "YES\n";
    }
}