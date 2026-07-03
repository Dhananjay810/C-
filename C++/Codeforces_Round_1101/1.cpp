#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        // int x=0,y=n-1;
        // while(v[x]!=a){
        //     x++;
        // }
        // while(v[y]!=a){
        //     y--;
        // }
        sort(v.begin(),v.end());
        int e=v[n/2];
        int ans1=0;
        int y=0;
        for(int i=0; i<n/2; i++){
            if(v[i]!=e) ans1++;
        }
        for(int i=n/2; i<n; i++){
            if(v[i]!=e) y++;
        }
        cout<<max(ans1,y)<<endl;
    }
}