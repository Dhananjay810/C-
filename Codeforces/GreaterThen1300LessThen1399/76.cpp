#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<vector<int>> v(m, vector<int>(2));
    vector<int> count(n, 0);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            count[i + 1] = count[i] + 1;
        } else {
            count[i + 1] = count[i];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
            v[i][j]--;
        }
        int x = count[v[i][1]] - count[v[i][0]];
        cout << x << endl;
    }
    
    return 0;
}