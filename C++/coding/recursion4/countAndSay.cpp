#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string say(int n){
    if(n==1) return "1";
    string str=say(n-1);
    char ch=str[0];
    int f=1;
    string h="";
    for(int i=1; i<str.size(); i++){
        char dh=str[i];
        if(ch==dh) f++;
        else{
            h=h+to_string(f)+ch;
            f=1;
            ch=dh;
        }
    }
    h=h+to_string(f)+ch;
    return h;
}
int main(){
    int n;
    cin>>n;
    cout<<say(n);
}