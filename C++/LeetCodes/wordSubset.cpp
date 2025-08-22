#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void sub(string ans, string s, vector<string>& v,string l,bool flag){
    if(s==""){
        if(ans.size()==l.size()){
        sort(l.begin(),l.end());
        sort(ans.begin(),ans.end());
        if(l==ans) cout<<"yes";
        }
        return;
    }
    char ch=s[0];
    if(s.length()==1){
        if(flag==true) sub(ans+ch,s.substr(1),v,l,true);
        sub(ans,s.substr(1),v,l,true);
        return;
    }
    char dh=s[1];
    if(ch==dh){
        if(flag==true) sub(ans+ch,s.substr(1),v,l,true);
        sub(ans,s.substr(1),v,l,false);
    }
    else{
        if(flag==true) sub(ans+ch,s.substr(1),v,l,true);
        sub(ans,s.substr(1),v,l,true);
    }
}
int main(){
    string s="apple";
    string l="oe";
    vector<string> v;
    sub("",s,v,l,true);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}