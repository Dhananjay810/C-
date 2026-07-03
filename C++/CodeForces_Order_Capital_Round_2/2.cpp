#include <bits/stdc++.h>
using namespace std;

int sw(int idx, vector<int> &v, vector<int> &vv){
    int n=v.size();
    int i=idx;
    while(i<n && v[i]>vv[i]){
        swap(v[i],v[i+1]);
        i++;
    }
    return i;
}

int main() {

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> vv(n);
        for(int i=0; i<n; i++) cin>>v[i];
        for(int i=0; i<n; i++) cin>>vv[i];
        for(int i=0; i<n; i++){
            if(v[i]>vv[n-1]){
                cout<<"-1"<<endl;
                continue;
            }
        }
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0; i<n; i++){
            if(v[i]>vv[i]){
                int u=sw(i,v,vv);
                int x=(u-i);
                ans+=x;
            }
        }
        cout<<ans<<endl;
    }
}