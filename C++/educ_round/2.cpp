#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        if(v[0]==1 && (v[1]==1 || v[1]==2)){
            cout<<"YES"<<endl;
            continue;
        }
        int i=1;
        int oon=0;
        int ot=0;
        if(v[0]==1) oon++;
        else if(v[0]==2 || v[0]==3) ot++;
        bool f1=false,f2=false;
        while(i<n){
            if(oon==ot){
                f1=true;
                break;
            }
            if(v[i]==1) oon++;
            else ot++;
            i++;
        }
        oon=0;
        int to=0,th=0;
        if(i==n){
            cout<<"NO"<<endl;
            continue;
        }
        if(v[i]==1) oon++;
        else if(v[i]==2) to++;
        else th++;
        i++;
        while(i<n){
            if(oon+to>=th){
                f2=true;
                break;
            }
            if(v[i]==1) oon++;
            else if(v[i]==2) to++;
            else th++;
            i++;
        }
        if(f1==true && f2==true && i<=n-1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}