#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(n==2){
            cout<<v[0]<<" "<<v[1]<<endl;
            continue;
        }
        bool flag=false;
        for(int i=0; i<n-2; i++){
            if(v[i+2]!=(v[i]%v[i+1])){
                cout<<"-1"<<endl;
                flag=true;
                break;
            }
        }
        if(flag==false) cout<<v[0]<<" "<<v[1]<<endl;
    }
}