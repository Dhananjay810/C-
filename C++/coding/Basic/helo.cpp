#include<iostream>
using namespace std;
int main(){
    cout<<4*3<<endl;
    float x = 3.14159;
    float y = 3.9;
    cout<<x/y<<endl;
    int z = 9;
    z = y + x;
    cout<<z<<endl;
    cout<<++x<<endl;
    // find remaider when 7 is divide by 2
    float a = 7; // a is dividend
    float b = 2; // b is divisor
    int q; // q is quitiont
    q = a/b;
    int r = a - q*b; // r is remainder
    cout<<r<<endl;

}