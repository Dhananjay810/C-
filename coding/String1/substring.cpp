#include<iostream>
#include<string>
using namespace std;
int main(){
    // string n = "abcdef";
    // // s.substr(idx,len)
    // cout<<n.substr(1,3);


    string n;
    cout<<"enter even string : ";
    cin>>n;
    int h=n.length();
    if(h%2==0){
        cout<<n.substr(h/2);
    }


}