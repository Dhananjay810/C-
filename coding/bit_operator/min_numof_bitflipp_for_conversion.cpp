#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int t=(m ^ n);
    cout<<__builtin_popcount(t)<<endl;
}