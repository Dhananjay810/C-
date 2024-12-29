#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    double a;
    a=((y*n)/100.0)-x;

    if(a<0){
        cout<<"0";
        return 0;
    }

    if(floor(a)!=a){
        cout<<floor(a)+1;
    }
    else cout<<a;

    // cout<<(int)a;
}