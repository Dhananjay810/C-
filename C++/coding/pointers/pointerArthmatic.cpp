#include<iostream>
using namespace std;
int main(){
    // int a=7;
    // a++;
    // cout<<a<<endl<<&a<<endl;


    // int* o= &a;
    // o=o+1;
    // cout<<o;
    // int* ptr=&a;
    // cout<<ptr<<endl;  // 0x61ff08

    // ptr=ptr+1;
    // cout<<ptr<<endl;  //  0x61ff0c

    // bool flag= true;
    // bool* ptr= &flag;
    // cout<<ptr<<endl;  // 0x61ff0b
    // ptr=ptr+1;
    // cout<<ptr<<endl;  // 0x61ff0c
    int x=4;
    int* ptr = &x;
    cout<<*ptr<<endl; //4
    (*ptr)++;  // x=x+1
    cout<<*ptr<<endl;// 5

    

}