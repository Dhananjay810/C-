#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        long long h=d-b;
        if(d<b){
            cout<<"-1"<<endl;
            continue;
        }
        // cout<<h<<" ";
        a=a+h;
        b=b+h;
        // cout<<a<<" "<<b<<" ";
        if(c>a){
            cout<<"-1"<<endl;
            continue;
        }
        long long g=a-c;
        // cout<<g<<endl;
        cout<<h+g<<endl;
    }
}