#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isdiff(string s){
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='F' && i<n-2){
            if(s[i+1]=='F' && s[i+2]=='T') return true;
        }
        if(s[i]=='N' && i<n-2){
            if(s[i+1]=='T' && s[i+2]=='T') return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(isdiff(s)==false){
            cout<<s<<endl;
            continue;
        }
        else{
            sort(s.begin(),s.end());
            reverse(s.begin(),s.end());
            cout<<s<<endl;
        }
    }
}