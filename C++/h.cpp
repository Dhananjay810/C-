#include<iostream>
#include<stack>
using namespace std;
void ff(stack<int> st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    ff(st);
    st.push(x);
    // cout<<x<<" ";
}
void f(stack<int> st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    cout<<x<<" ";
    f(st);
    ff(st);
    st.push(x);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    f(st);
    cout<<endl<<"sdfvfe"<<endl;
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
    }
}