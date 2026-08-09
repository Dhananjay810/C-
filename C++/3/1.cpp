#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int maxa=0;
        for(int i=0; i<n; i++){
            if(s[i]=='*') continue;
            int ln=0;
            while(i<n && s[i]=='#'){
                i++;
                ln++;
            }
            maxa=max(maxa, ln);
        }
        int ans=maxa/2;
        if(ans*2!=maxa) ans++;
        cout<<ans<<endl;
    }
    return 0;
}