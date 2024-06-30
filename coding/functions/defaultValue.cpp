#include<iostream>
using namespace std;
int fun(int x=7, int y=8){ //not default value
    cout<<x<<endl<<y<<endl;
}
int main(){
    // int x=7;
    // int y=3;
     fun(11,10); //default value
}