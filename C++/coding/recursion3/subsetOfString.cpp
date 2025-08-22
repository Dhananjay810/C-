#include<iostream>
using namespace std;

// wwithout indexing
void sub(string ans, string s){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    sub(ans,s.substr(1));
    sub(ans+s[0],s.substr(1));
}

// with indexing
void sub2(string ans, string s,int idx){
    if(idx==s.size()){
        cout<<ans<<endl;
        return;
    }
    sub2(ans,s,idx+1);
    sub2(ans+s[idx],s,idx+1);
}
int main(){
    string s;
    cin>>s;
    sub("",s);
    cout<<endl;
    sub2("",s,0);
}