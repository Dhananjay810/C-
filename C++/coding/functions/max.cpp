#include<iostream>
using namespace std;
int f(int a, int b, int c){
    int u=max(a,b);
    int y=max(u,c);
    return y;
}
int main(){
    int a,b,c;
    cout<<"enter a,b,c : ";
    cin>>a>>b>>c;
    int j=f(a,b,c);
    cout<<"greatest is : ";
    cout<<j;
}