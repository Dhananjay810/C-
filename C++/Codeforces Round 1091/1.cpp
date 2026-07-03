#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        int sum=0;
        for(int i=0; i<n; i++){
            cin>>v[i];
            sum+=v[i];
        }
        // cout<<sum<<endl;
        if(sum%2!=0){
            cout<<"YES"<<endl;
            continue;
        }
        if(n*k%2==0){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}