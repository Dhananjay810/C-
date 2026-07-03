#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        int ans=0;
        int nn=n;
        while(nn>0){
            ans++;
            nn=nn-x;
            nn=nn-y;
        }
        // cout<<ans<<" ";
        int ans2=0;
        int e=z*x;
        if(e>=n){
            if(e==n) ans2=e;
            else ans2=ceil((double)n/x);
        }
        else{
            int h=n-e;
            ans2+=z;
            while(h>0){
                ans2++;
                h=h-(10*y);
                h=h-x;
            }
        }
        cout<<min(ans,ans2)<<endl;
    }
}