#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void sub(string ans,string s){
    if(s==""){
        cout<<ans<<endl;
        return;
    }
    int n=s.size();
    for(int i=0; i<n; i++){
        char ch=s[i];
        string l=s.substr(0,i);
        string r=s.substr(i+1);
        sub(ans+ch,l+r);
    }
}
int main(){
    string s;
    cin>>s;
    cout<<endl;
    sub("",s);
    
}