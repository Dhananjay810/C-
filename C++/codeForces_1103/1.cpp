#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int mini=INT_MAX;
        int maxa=INT_MIN;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mini=min(mini,x);
            maxa=max(maxa,x);
        }
        maxa=maxa+1;
        int ans=maxa-mini;
        cout<<ans<<endl;
    }
}