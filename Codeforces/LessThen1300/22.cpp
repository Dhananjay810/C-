#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++){
        string h;
        cin>>h;
        int u=h.length();
        if(u>10){
            s[i]=h[0]+to_string(u-2)+h[u-1];
        }
        else{
            s[i]=h;
        }
    }
    for(int i=0;i<n; i++){
        cout<<s[i]<<endl;
    }
}