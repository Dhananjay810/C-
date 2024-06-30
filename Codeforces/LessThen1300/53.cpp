#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if((int)s[i]>=97 && (int)s[i]<=122) continue;
        else{
            s[i]=(char)((int)s[i]+32);
        }
    }
    for(int i=0; i<s.size(); i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y'){
            continue;
        }
        else{
            cout<<"."<<s[i];
        }
    }
}