#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    long long int ans=0;
    for(int i=1; i<n; i++){
        if(v[i]<v[i-1]){
            ans=ans+(v[i-1]-v[i]);
            v[i]=v[i-1];
        }
    }
    cout<<ans;
}