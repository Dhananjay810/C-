#include<iostream>
#include<stack>
using namespace std;
void printrev(stack<int>& d){
    if(d.size()==0) return;
    cout<<d.top()<<" ";
    int u=d.top();
    d.pop();
    printrev(d);
    d.push(u);
}

void print(stack<int>& d){
    if(d.size()==0) return;
    int u=d.top();
    d.pop();
    print(d);
    cout<<u<<" ";
}

int main(){
    stack<int> st;
    for(int i=0; i<5; i++){
        st.push(i+45);
    }
    printrev(st);
    cout<<endl;
    print(st);
}