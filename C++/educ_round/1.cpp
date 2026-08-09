#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<int> v(k);
        for(int i=0; i<k; i++) cin>>v[i];
        bool f1=false;
        bool f2=false;
        for(int i=0; i<k; i++){
            if(v[i]>2){
                cout<<"YES"<<endl;
                f1=true;
                f2=true;
                break;
            }
            else if(v[i]>=2 && f1==false) f1=true;
            else if(v[i]>=2 && f1==true){
                cout<<"YES"<<endl;
                f2=true;
                break;
            }
        }
        if(f1==false || f2==false) cout<<"NO"<<endl;
    }
}