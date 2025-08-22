#include<iostream>
#include<stack>
using namespace std;

void disp(stack<int> v){
    while(v.size()>0){
        cout<<v.top()<<" ";
        v.pop();
    }
    cout<<endl;
}

void pushAtBott(stack<int>& st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int u=st.top();
    st.pop();
    pushAtBott(st,val);
    st.push(u);
}

void rev(stack<int>& v){
    if(v.size()==1) return;
    int u=v.top();
    v.pop();
    rev(v);
    pushAtBott(v,u);
}

int main(){
    stack<int> st;
    for(int i=0; i<4; i++){
        st.push(i*10+10);
    }
    disp(st);
    rev(st);
    disp(st);
}