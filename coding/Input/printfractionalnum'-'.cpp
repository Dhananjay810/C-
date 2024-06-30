#include<iostream>
using namespace std;
int main(){
    float x;
    cout<<"enter negetive no. of x :";
    cin>>x; //-1.3
    int y = (int)x; //-0.3
    cout<<"fractional part of no is :"
    cout<<1+(x-y); // 1 +(-0.3)
}