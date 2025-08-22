#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int idx=-1;
        for(int i=0; i<n; i++){
            if(v[i]==1){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            cout<<"YES"<<endl;
            continue;
        }
        if(idx+x>=n){
            cout<<"YES"<<endl;
            continue;
        }
        idx=idx+x;
        bool flag=false;
        for(int i=idx; i<n; i++){
            if(v[i]==1){
                cout<<"NO"<<endl;
                flag=true;
                break;
            }
        }
        if(flag==false) cout<<"YES"<<endl;
    }
}