#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    int l;
    cin>>l;
    int m;
    cin>>m;
    int n;
    cin>>n;
    int d;
    cin>>d;
    int t=0;
    for(int i=1; i<=d; i++){
        if((i%k==0) || (i%l==0) || (i%m==0) || (i%n==0)) t=t+1;
    }
    cout<<t;
}