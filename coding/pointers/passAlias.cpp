#include<iostream>
using namespace std;
void swap(int &a, int &b){   // pass by referance 
    int tamp=a;
    a=b;
    b=tamp;
    return;
}
int main(){
    int a,b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<" "<<b;
}