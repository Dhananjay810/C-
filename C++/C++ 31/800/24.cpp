#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        // if(n==1){
        //     cout<<v[0]<<endl;
        //     continue;
        // }
        // if(n==2){
        //     if(v[0]!=v[1]){
        //         cout<<"-1"<<endl;
        //         continue;
        //     }
        // }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=ans xor v[i];
        }
        int u=0;
        vector<int> x(n);
        for(int i=0; i<n; i++){
            x[i]=v[i] ^ ans;
        }
        for(int i=0; i<n; i++){
            u=u ^ x[i];
        }
        // cout<<u<<endl;
        if(u!=0) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
}