#include<iostream>
#include<stack>
#include<string>
using namespace std;
int sol(int val1, int val2, char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    return val1/val2;
}
int main(){
    string s="-/*+79483";
    stack<int> val;
    int n=s.size();
    for(int i=n-1; i>=0; i--){
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);
        else{
            char ch=s[i];
            int val1=val.top();
            val.pop();
            int val2=val.top();
            val.pop();
            int ans=sol(val1,val2,ch);
            val.push(ans);
        }
    }
    cout<<val.top();
}