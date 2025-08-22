#include<iostream>
#include<vector>
using namespace std;
class Stack{
public:
    vector<int> v;
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        if(v.size()==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        v.pop_back();
    }
    int top(){
        return v[v.size()-1];
    }
    int size(){
        return v.size();
    }
};
int main(){
    Stack st;
    st.push(90);
    st.push(100);
    cout<<st.size()<<endl;
    cout<<st.top();
}