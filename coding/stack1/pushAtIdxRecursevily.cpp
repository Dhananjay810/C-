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

void pushAtIdx(stack<int>& st,int idx, int val){
    if(st.size()==idx){
        st.push(val);
        return;
    }
    int u=st.top();
    st.pop();
    st.push(u);
}

int main(){
    stack<int> st;
    for(int i=0; i<7; i++){
        st.push(i+96);
    }
    disp(st);
    int idx=2,val=23;
    pushAtIdx(st,idx,val);
    disp(st);
}