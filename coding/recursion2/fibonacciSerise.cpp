#include<iostream>
using namespace std;
void fibo(int n,int y,int z){
    if(n==0) return;
    cout<<y+z<<" ";
    int h=y;
    y=z;
    z=z+h;
    fibo(n-1,y,z);
}
int main(){
    int n;
    cin>>n;
    fibo(n,0,1);
}