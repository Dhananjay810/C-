#include<iostream>
using namespace std;
int sum(int n){
    if(n==1) return 1;
    return n+sum(n-2);
}
int main(){
    int n;
    cin>>n;
    if(n%2==0) cout<<sum(n-1);
    else cout<<sum(n);
}