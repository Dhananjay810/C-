#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k,x;
        cin>>n>>k>>x;
        long long int sm=(k*(k+1))/2;
        long long int i=n;
        long long int c=((n*(n+1))/2)-(((n-k)*(n-k+1))/2);
        if(x>=sm && x<=c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}