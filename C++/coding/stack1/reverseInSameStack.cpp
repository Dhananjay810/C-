#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    int y=548;
    for(int i=0; i<7; i++){
        st.push(y);
        y+=18;
    }
    stack<int> temp1;
    //emptying st
    while(st.size()>0){
        temp1.push(st.top());
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    stack<int> temp2;
    //enptying temp1
    while(temp1.size()>0){
        temp2.push(temp1.top());
        temp1.pop();
    }
    //emptying temp2
    while(temp2.size()>0){
        st.push(temp2.top());
        temp2.pop();
    }
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
    }


    // ALSO WE CAN REVERSE STACK USING ARRAY
}