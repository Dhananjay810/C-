#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    int u=18;
    for(int i=0; i<7; i++){
        st.push(u);
        u+=2;
    }

    // print in froward dir. using SC O(n)

    stack<int> stt;


    // print in reverse order --> empptying the stack
    while(st.size()>0){
        cout<<st.top()<<" ";
        stt.push(st.top()); // copy element 
        st.pop();
    }
    cout<<endl;
    while(stt.size()>0){
        cout<<stt.top()<<" ";
        st.push(stt.top());
        stt.pop();
    }
}