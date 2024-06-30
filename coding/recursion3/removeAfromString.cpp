#include<iostream>
using namespace std;
void remo(string ans,string orig,int idx){
    if(idx==orig.size()){
        cout<<ans;
        return;
    }
    if(orig[idx]!='a') ans.push_back(orig[idx]);
    remo(ans,orig,idx+1);
}

void remo2(string answer,string s){
    if(s.size()==0){
        cout<<answer;
        return;
    }
    char ch=s[0];
    if(ch=='n') remo2(answer,s.substr(1));
    else remo2(answer+ch,s.substr(1));
}
int main(){
    string s="Dhananjay";
    remo("",s,0);
    cout<<" ";
    remo2("",s);
}