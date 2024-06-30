#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    //cout<<s;
    string t[(s.length()/2)+1]; 
   // int y=0;
    for(int i=(s.length()/2); i<s.length(); i++){
        if(i!=s.length()-1){
            cout<<s[i]<<"+";
        }
        else cout<<s[i];
       
    }
    
    // string f[s.length()];
    // for(int i=0; i<s.length(); i++){
    //     f[i]='0';
    // }
    // for(int i=0; i<s.length(); i++){
    //     if((int)s[i]!=43){
    //         f[i]=s[i];
    //     }
    //     else continue;
    // }
    // sort(f.begin(),f.end());
    // for(int i=0; i<(s.length()+6)/4; i++){
    //     cout<<t[i];
    // }
}