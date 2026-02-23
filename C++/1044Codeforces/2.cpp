#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        long long int ans=0;
        sort(v.begin(),v.end());
        for(int i=n-1; i>=0; i-=2){
            if(i>0){
                long long y=max(v[i],v[i-1]);
                ans+=y;
            }
            else if(i==0) ans+=v[i];
        }
        cout<<ans<<endl;
    }
}