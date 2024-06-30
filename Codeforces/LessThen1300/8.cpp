#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int u=(int)s[0];
    if(u>=97 && u<=122){
        u=u-32;
        s[0]=(char)u;
    }
    cout<<s;
}