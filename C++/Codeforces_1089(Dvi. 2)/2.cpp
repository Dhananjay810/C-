#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<bool> &mark, vector<int> &p, int count){
    if(i==p.size()) return count;
    int a=0;
    int b=0;
    if(mark[i]!=true){
        mark[p[i]]=true;
        a = f(i+1, mark, p, count+1);
        mark[p[i]]=false;
        b = f(i+1, mark, p, count);
        return max(a, b);
    }
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
        }

        vector<bool> marked(n, false);

        int ans = 0;

        ans=f(1,marked, p, 0);

        cout << ans << '\n';
    }
}