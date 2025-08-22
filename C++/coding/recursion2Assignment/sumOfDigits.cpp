#include<iostream>
using namespace std;
int sum(int n, int s){
    if(n==0) return s;
    return sum(n/10,s+n%10);
}
int sum2(int n){
    if(n==0) return 0;
    return n%10+sum2(n/10);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n,0);

    cout<<endl<<endl<<sum2(n);
}