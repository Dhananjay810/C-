#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            int f;
            cin>>f;
            if(f%2==0) v[i]=0;
            else v[i]=1;
        }
        vector<int> pre(n+1);
        pre[1]=v[0];
        for(int i=1; i<n; i++) pre[i+1]=pre[i]+v[i];
        // for(int i=0; i<n+1; i++) cout<<pre[i]<<" ";
        // cout<<endl;
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            // r--;
            // l--;
            int prev_sum=pre[r]-pre[l-1];
            // cout<<prev_sum<<endl;
            int left=pre[n]-prev_sum;
            // cout<<left<<endl;
            if(k%2==0){
                if(left%2==0) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
                continue;
            }
            int y=(r-l+1);
            if((left+y)%2==0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}