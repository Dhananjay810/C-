#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

vector<vector<int>> dir={{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};

int bfs(int srcr, int srcc, int destr, int destc) {
    vector<vector<bool>> visited(9, vector<bool>(9, false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{srcr, srcc}, 0});
    visited[srcr][srcc] = true;

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int le = q.front().second;
        q.pop();

        if (r == destr && c == destc) return le;

        for (int i = 0; i < 8; i++) {
            int newr = r + dir[i][0];
            int newc = c + dir[i][1];
            if (newr > 0 && newc > 0 && newr <= 8 && newc <= 8 && !visited[newr][newc]) {
                visited[newr][newc] = true;
                q.push({{newr, newc}, le + 1});
            }
        }
    }
    return -1; // Return -1 if no path is found (though it shouldn't happen on a chessboard)
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string src, dest;
        cin >> src >> dest;
        int srcr = src[1] - '0';
        int srcc = src[0] - 'a' + 1;
        int destr = dest[1] - '0';
        int destc = dest[0] - 'a' + 1;

        int moves = bfs(srcr, srcc, destr, destc);
        cout << moves << endl;
    }
    return 0;
}
