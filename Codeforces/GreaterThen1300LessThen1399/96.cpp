#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int n,t;
    cin>>n>>t;
    vector<long long int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // vector<int> s(n);
    // s[0]=v[0];
    // for(int i=1; i<n; i++){
    //     s[i]=v[i]+s[i-1];
    // }
    long long int x=0;
    for(int i=0; i<n; i++){
        long long int b=0;
        long long int idx=-1;
        for(int j=i; j<n; j++){
            b+=v[j];
            if(b>t){
                idx=j;
                break;
            }
        }
        if(idx==-1){
            if((n-i)>x) x=(n-i);
        }
        if((idx-i)>x) x=(idx-i);
    }
    cout<<x;
}