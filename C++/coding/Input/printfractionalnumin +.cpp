#include<iostream>
using namespace std;
int main(){
    float x;
    cout<<"enter the no. :";
    cin>>x; // 9.8
    int y = (int)x;  // x = 9
    cout<<"fractional part of the no. is :";
    cout<<x-y; // 9.8-9
}