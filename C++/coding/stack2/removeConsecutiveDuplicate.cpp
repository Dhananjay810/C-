#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> st;
    st.push(s[s.size()-1]);
    for(int i=s.size()-2; i>=0; i--){
        if(s[i]!=st.top()) st.push(s[i]);
    }
    string h="";
    while(st.size()>0){
        h+=st.top();
        st.pop();
    }
    cout<<h<<endl;
}