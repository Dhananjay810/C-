#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s="";
    while(n>0){
        if(n%2==0) s='0'+s;
        else s='1'+s;

        n=n>>1;  // bit operator

       // n=n/2;
    }
    cout<<s;
}