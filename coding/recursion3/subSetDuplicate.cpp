#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void sub(string ans, string s, vector<string>& v,bool flag){
    if(s==""){
        v.push_back(ans);
        return;
    }
    char ch=s[0];
    if(s.length()==1){
        if(flag==true) sub(ans+ch,s.substr(1),v,true);
        sub(ans,s.substr(1),v,true);
        return;
    }
    char dh=s[1];
    if(ch==dh){
        if(flag==true) sub(ans+ch,s.substr(1),v,true);
        sub(ans,s.substr(1),v,false);
    }
    else{
        if(flag==true) sub(ans+ch,s.substr(1),v,true);
        sub(ans,s.substr(1),v,true);
    }
}
int main(){
    string s="google";
    vector<string> v;
    sub("",s,v,true);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}