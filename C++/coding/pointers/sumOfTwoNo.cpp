#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter two no. : ";
    cin>>a>>b;
    int* o= &a;
    int* g= &b;
    int u=*o+*g;
    cout<<u;
}