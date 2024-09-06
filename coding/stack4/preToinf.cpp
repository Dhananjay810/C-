#include<iostream>
#include<stack>
#include<string>
using namespace std;
string sol(string val1, string val2, char ch){
    string h="";
    h=h+val1;
    h.push_back(ch);
    h=h+val2;
    return h;
}
int main(){
    string s="-/*+79483";
    stack<string> val;
    int n=s.size();
    for(int i=n-1; i>=0; i--){
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));
        else{
            char ch=s[i];
            string val1=val.top();
            val.pop();
            string val2=val.top();
            val.pop();
            string ans=sol(val1,val2,ch);
            val.push(ans);
        }
    }
    cout<<val.top();
}