#include<iostream>
using namespace std;
int main(){
    string str = "abc";
    cout<<str<<endl;
    str = str + "xyz";
    cout<<str<<endl;
    str = "xyz" + str;
    cout<<str<<endl;
}