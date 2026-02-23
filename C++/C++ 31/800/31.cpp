#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        if(n==a && a==b){
            cout<<"Yes"<<endl;
            continue;
        }
        int x=a+b;
        if(x<=n-2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}