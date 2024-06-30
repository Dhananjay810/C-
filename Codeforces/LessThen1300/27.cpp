#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    string d;
    cin>>d;
    int u=0;
    for(int i=0; i<s.length(); i++){
        if((int)s[i]>=97 && (int)s[i]<=122){
            s[i]=(char)(int)s[i]-32;
        }
        else continue;
    }
     for(int i=0; i<s.length(); i++){
        if((int)d[i]>=97 && (int)d[i]<=122){
            d[i]=(char)(int)d[i]-32;
        }
        else continue;
    }
    for(int i=0; i<s.length(); i++){
        if((int)s[i]==(int)d[i]){
            u++;
        }
        else if((int)s[i]>(int)d[i]){
        cout<<"1";
        break;
        }
        else{
            cout<<"-1";
            break;
        }

    
    }

    if(u==s.length()){
        cout<<"0";
    }
    
}