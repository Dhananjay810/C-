#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int s,k,m;
        cin>>s>>k>>m;
        int time=m/k;
        int rem=m%k;
        int left=0;
        if(s<=k) left=s;
        else{
            if(time%2==0) left=s;
            else left=k;
        }
        if(left<=rem) cout<<"0"<<endl;
        else cout<<left-rem<<endl;
    }
}