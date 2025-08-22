#include<iostream>
using namespace std;
bool flag(int n,int m){
    if(m==n) return true;
    else if(m>n) return false;
    m=m*2;
    flag(n,m);
}
int main(){
    int n;
    cin>>n;
    if(flag(n,2)) cout<<"Yes";
    else cout<<"No";
}