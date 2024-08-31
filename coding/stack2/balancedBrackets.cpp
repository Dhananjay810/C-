#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isBalanced(string s, stack<char>& st){
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(st.size()==0) return false;
            st.pop();
        }
    }
    if(st.size()>0) return false;
    return true;
}
int main(){
    string s;
    cin>>s;
    stack<char> st;
    cout<<isBalanced(s,st);
    
}