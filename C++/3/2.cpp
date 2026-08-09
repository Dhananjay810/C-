#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;
        vector<long long> v(n);
        long long sum=0;
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        long long carry=0;
        long long cnt=1;
        bool flag=true;
        for(int i=0; i<n; i++){
            long long y=carry+v[i];
            if(y<cnt){
                flag=false;
                cout<<"NO"<<endl;
                break;
            }
            carry=y-cnt;
            cnt++;
        }
        if(flag==true) cout<<"YES"<<endl;
    }

    return 0;
}