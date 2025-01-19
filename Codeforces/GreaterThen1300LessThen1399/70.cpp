#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> v;
    long long ans=0;
    for(int i=0; i<n; i++){
        long long num;
        cin>>num;
        if(num<1){
            ans=ans+(1-num);
            num=1;
        }
        if(num>n){
            ans=ans+(num-n);
            num=n;
        }
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    vector<long long> b(n);
    for(int i=0; i<n; i++){
        b[i]=i+1;
    }
    for(int i=0; i<n; i++){
        ans+=abs(v[i]-b[i]);
    }
    cout<<ans;
}