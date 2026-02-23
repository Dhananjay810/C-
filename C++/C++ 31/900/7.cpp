#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(),v.end());
        
        long long maxa=0;
        long long sz1=1;
        for(int i=0; i<n-1; i++){
            long long f = v[i+1]-v[i];
            if(f<=k) sz1++;
            else{
                maxa=max(maxa,sz1);
                // cout<<maxa<<" ";
                sz1=1;
            }
        }

        maxa=max(maxa,sz1);
        
        // int sz2=0;
        // for(int i=n-1; i>0; i--){
        //     int f = v[i]-v[i-1];
        //     if(f<=k) sz2++;
        //     else{
        //         maxa=max(maxa,s1)
        //     }
        // }
        // if(sz1<sz2){
        //     cout<<n-sz2-1<<endl;
        // }
        // else{
        //     cout<<n-sz1-1<<endl;
        // }
        cout<<n-maxa<<endl;
    }
}