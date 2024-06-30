#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    if(n==1){
        cout<<s[0];
    }
    else{
    string h[2];
    h[0]=s[0];
    for(int i=0; i<n; i++){
        if(s[i]!=h[0]){
            h[1]=s[i];
            break;
        }
        else continue;
    }
   // cout<<h[0]<<" "<<h[1];
    int u=0,y=0;
    for(int i=0; i<n; i++){
       if(h[0]==s[i]){
        u++;
       }
       else y++;
    }
    if(u>y){
        cout<<h[0];
    }
    else{
        cout<<h[1];
    }
    }
}