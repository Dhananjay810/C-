#include<iostream>
#include<stack>
using namespace std;
void pushAtBott(stack<int>& s,int val){
    stack<int> temp;
    while(s.size()>0){
        temp.push(s.top());
        s.pop();
    }
    s.push(val);
    while(temp.size()>0){
        s.push(temp.top());
        temp.pop();
    }
}

void pushAtIdx(stack<int>& s,int val,int idx){
    stack<int> temp;
    while(s.size()>idx){
        temp.push(s.top());
        s.pop();
    }
    s.push(val);
    while(temp.size()>0){
        s.push(temp.top());
        temp.pop();
    }
}

void print(stack<int> s){
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
        }
        cout<<endl;
}
int main(){
    stack<int> st;
    for(int i=0; i<4; i++){
        st.push(i+100);
    }
    print(st);
    pushAtBott(st,70);
    // push 70 at bottom
    // stack<int> temp;
    // while(st.size()>0){
    //     temp.push(st.top());
    //     st.pop();
    // }
    // st.push(70);
    // while(temp.size()>0){
    //     st.push(temp.top());
    //     temp.pop();
    // }
    print(st);

    // at any idx

    pushAtIdx(st,79,2);
    // push 69 at idx 2
    // int idx=2;
    // while(st.size()>idx-1){
    //     temp.push(st.top());
    //     st.pop();
    // }
    // st.push(69);
    // while(temp.size()>0){
    //     st.push(temp.top());
    //     temp.pop();
    // }
    print(st);
}