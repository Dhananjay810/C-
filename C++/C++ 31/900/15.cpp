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
        int ans=0;
        bool flag=false;
        for(int i=n-1; i>0; i--){
            while(v[i-1]>=v[i]){
                v[i-1]=(v[i-1])/2;
                if(v[i-1]==0 && i>1){
                    cout<<"-1"<<endl;
                    flag=true;
                    break;
                }
                ans++;
            }
            if(flag==true) break;
        }
        if(flag==true) continue;
        cout<<ans<<endl;
    }
}