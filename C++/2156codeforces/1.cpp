#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int ans=0;
        while(n>=3){
            long long int a=n/3;
            ans+=a;
            long long int b=n-a;
            long long int c=b/2;
            long long int d=b-c;
            n=d;
        }
        cout<<ans<<endl;
    }
}