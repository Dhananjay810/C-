#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int g=0;
    for(int i=0; i<s.length(); i++){
        if((s[i]=='4' || s[i]=='7')){
            g++;
        }
        else{
            continue;
        }
    }
    if(g==4 || g==7){
        cout<<"YES";
    }
    else cout<<"NO";
}
