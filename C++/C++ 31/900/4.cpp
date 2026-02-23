#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,n;
        cin>>a>>b>>n;
        vector<long long> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(),v.end());

        long long ans=0;
        long long i=0;
        while(true){
            if(b>1){
                ans=ans+(b-1);
                b=1;
            }
            else{
                b=b+v[i];
                b=min(b,a);
                if(b==1){
                    break;
                }
                b--;
                ans++;
                i++;
                if(i>=n){
                    ans=ans+(b-1);
                    break;
                }
            }
        }
        ans=ans+1;
        cout<<ans<<endl;
    }
}