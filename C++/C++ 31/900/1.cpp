#include <iostream>
#include <vector>
#include<climits>
#include<set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int xk, yk;
        cin >> xk >> yk;
        int xq, yq;
        cin >> xq >> yq;

        vector<vector<int>> king(8, vector<int>(2));
        vector<vector<int>> queen(8, vector<int>(2));
        vector<vector<int>> dir = {
            {a, b}, {b, a}, {-b, a}, {-a, b},
            {-b, -a}, {-a, -b}, {a, -b}, {b, -a}
        };

        set<pair<int,int>> kk,qq;

        for (int i = 0; i < 8; i++) {
            int xx = xk - dir[i][0];
            int yy = yk - dir[i][1];
            kk.insert({xx,yy});
        }

        for (int i = 0; i < 8; i++) {
            int xx = xq - dir[i][0];
            int yy = yq - dir[i][1];
            qq.insert({xx,yy});
        }
        

        int ans=0;
        for(auto x : kk){
            if(qq.find(x)!=qq.end()) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
