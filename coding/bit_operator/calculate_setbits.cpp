#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    //inbuilt function
    cout<<__builtin_popcount(n)<<endl;


    // method 2

    int sum=0;
    int m=n;
    while(m>0){
        if(m%2==1) sum++;
        m=m>>1;
    }
    cout<<sum<<endl;


    //method 3

    int count=0;
    while(n>0){
        count++;
        n=n&(n-1);
    }
    cout<<count<<endl;
}