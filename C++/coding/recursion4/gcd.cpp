#include<iostream>
using namespace std;
int gcd(int a,int b){ //TC=O(min(a,b))
    for(int i=min(a,b); i>=2; i--){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}
int gcd2(int a,int b){
    if(b%a==0) return a;
    gcd2(b%a,a);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd2(a,b);
}