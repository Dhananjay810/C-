#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string h="ZZZYYES";
    //cin>>h;
    string s="";
    for(int i=0; i<h.length(); i++){
        if(h[i]>='X'){
            s.push_back(s[i]);
        }
        else continue;
    }
    // for(int i=0; i<s.length(); i++){
    //     cout<<*s[i];
    // }
    cout<<s;
}