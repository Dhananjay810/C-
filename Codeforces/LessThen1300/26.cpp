#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int t=0;
    bool u=false;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='H'|| s[i]=='Q' || s[i]=='9'){
           u=true;
           break;
        }
        else{
            u=false;
            continue;
        }
    }
    if(u==true){
        cout<<"YES";
    }
    else cout<<"NO";

}