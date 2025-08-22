#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    cout<<st.size()<<endl;
    st.push(15);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.push(14);
    cout<<st.top()<<endl;
    st.push(157);
    st.push(140);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
}