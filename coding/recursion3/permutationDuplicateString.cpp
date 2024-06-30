#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void per(string ans,string s){
    if(s==""){
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<s.size(); i++){
        char ch=s[i];
        if(i==0){
                string l=s.substr(0,i);
                string r=s.substr(i+1);
                per(ans+ch,l+r);
        }
         else{
            if(ch!=s[i-1]){
                string l=s.substr(0,i);
                string r=s.substr(i+1);
                per(ans+ch,l+r);
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    cout<<endl;
    sort(s.begin(),s.end());
    per("",s);
}