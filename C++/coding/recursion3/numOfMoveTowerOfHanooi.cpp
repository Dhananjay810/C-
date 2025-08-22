#include<iostream>
using namespace std;
int tow(int n){
    if(n==1) return 1;
    return tow(n-1)+tow(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<tow(n);
}