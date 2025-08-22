#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        vector<int> v(n);
        int mini=INT_MAX;
        int maxa=INT_MIN;
        for(int i=0; i<n; i++){
            cin>>v[i];
            mini=min(mini,v[i]);
            maxa= max(maxa,v[i]);
        }
        // mini=abs(mini);
        // maxa=abs(maxa);

        int minid=abs(s-mini);
        int maxad=abs(maxa-s);
        if((mini>s && maxa>s) || (mini<s && maxa<s)){
            int u=max(maxad,minid);
            cout<<u<<endl;
            continue;
        }
        int ans=0;
        if(maxad>minid){
            ans+=(2*minid);
            ans+=maxad;
        }
        else{
            ans+=(2*maxad);
            ans+=minid;
        }
        cout<<ans<<endl;
    }
}