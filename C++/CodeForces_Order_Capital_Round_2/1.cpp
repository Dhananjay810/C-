#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                v[j]=min(v[i],v[j]);
            }
        }
        for(int i=0; i<n; i++) ans+=v[i];
        cout<<ans<<endl;
    }
}