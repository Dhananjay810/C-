#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m=n;

    int y=n;

    // method 1

    int temp;
    while(n!=0){
        temp=n;
        n=n&(n-1);
    }
    temp=temp<<1;
    temp=temp-1;
    cout<<(m ^ temp)<<endl;

    // method 2

    m=m|m>>1;
    m=m|m>>2;
    m=m|m>>4;
    m=m|m>>8;
    m=m|m>>16;

    cout<<(y ^ m);
}