#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
   // cout<<"enter word : ";
    getline(cin,s);
    int x=0,y=0;
    for(int i=0; i<s.length(); i++){
        int u=(int)s[i];
        if(u>=65 && u<=90){
            x++;
        }
        else if(u>=97 && u<=122){
            y++;
        }
        else continue;
    }
    if(x>y){
        for(int i=0; i<s.length(); i++){
            int u=(int)s[i];
             if(u>=97 && u<=122){
                u=u-32;
                s[i]=(char)u;
        }
        else continue;
        }
    }
    else{
        for(int i=0; i<s.length(); i++){
            int u=(int)s[i];
             if(u>=65 && u<=90){
                u=u+32;
                s[i]=(char)u;
        }
        else continue;
        }
    }
    cout<<s;
}