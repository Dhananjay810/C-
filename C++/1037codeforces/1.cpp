#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=INT_MAX;
        while(n>0){
            int rem=n%10;
            ans=min(ans,rem);
            n=n/10;
        }
        cout<<ans<<endl;
    }
}