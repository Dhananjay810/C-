#include<iostream>
using namespace std;
int main(){
    int x=4;
    int* j= &x; // int*  --> data type  storing the path os x
    // or int *p= &x   SAME

    cout<<&x<<endl;
    cout<<j<<endl<<&j;
}