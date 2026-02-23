#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int aa,bb;
        cin>>aa>>bb;
        int a=aa;
        int b=bb;
        int ans=0;
        int u=1;
        long long y=1;
        while(a>=0 && b>=0){
            if(u%2!=0){
                if((a-y)<0) break;
                a=a-y;
                ans++;
            }
            else{
                if((b-y)<0) break;
                b=b-y;
                ans++;
            }
            u++;
            y=2*y;
        }
        // cout<<ans<<"fd"<<endl;
        a=aa;
        b=bb;
        y=1;
        int ans2=0;
        u=1;
        while(a>=0 && b>=0){
            if(u%2!=0){
                if((b-y)<0) break;
                b=b-y;
                ans2++;
            }
            else{
                if((a-y)<0) break;
                a=a-y;
                ans2++;
            }
            u++;
            y=2*y;
        }
        cout<<max(ans,ans2)<<endl;
    }
}