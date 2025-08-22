#include<iostream>
using namespace std;
int main(){
    int a = 11; // a is dividend
    int b = 3; // b is divisor
    int q = a/b; // q is quotient
    // a = q*b + r, where r is remainder
    cout<< a - b*q<<endl;
    cout<<a % b; //(this also direct ethod to find the remainder)
}