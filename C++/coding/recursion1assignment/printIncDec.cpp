#include<iostream>
using namespace std;
void print(int n,int m){
    if(m>n) return;
    cout<<m<<" ";
    print(n,m+1);
    if(m!=n) cout<<m<<" ";
}
int main(){
    int n;
    cin>>n;
    print(n,1);
}