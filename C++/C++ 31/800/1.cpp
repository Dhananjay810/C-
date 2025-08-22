#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        bool flag=false;
        for(int i=0; i<n-1; i++){
            if(v[i]<=v[i+1]){
                flag=true;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==true){
            cout<<"YES"<<endl;
            continue;
        }
        if(k==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}