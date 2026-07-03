#include <bits/stdc++.h>
using namespace std;
bool isPlandrome(long long n){
    string s=to_string(n);
    string t=s;
    reverse(t.begin(),t.end());
    if(s==t) return true;
    else return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        bool flag=false;
        long long rem=n%12;
        // cout<<rem<<endl;
        if(rem!=10){
            cout<<rem<<" "<<n-rem<<endl;
            continue;
        }
        else if(rem==10){
            for(long long i=12; i<=n; i+=12){
                if(isPlandrome(n-i)){
                    cout<<n-i<<" "<<i<<endl;
                    flag=true;
                    break;
                }
            }
        }
        if(flag==false) cout<<"-1"<<endl;
    }
}