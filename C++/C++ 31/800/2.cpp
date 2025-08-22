#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int ans=INT_MIN;
        int y=0;
        for(int i=0; i<n; i++){
            ans=max(ans,v[i]-y);
            y=v[i];
        }
        ans=max(ans,2*(x-y));
        cout<<ans<<endl;
    }
}
