#include<iostream>
using namespace std;
class Stack{
public:
    int arr[5];
    int idx=-1;
    void push(int val){
        if(idx==5) cout<<"full"<<endl;
        else{
            idx++;
            arr[idx] = val;
        }
    }
    void pop(){
        if(idx=-1) cout<<"empty"<<endl;
        else idx--;
    }
    void top(){
        if(idx==-1) cout<<"enpty"<<endl;
        else cout<<arr[idx]<<endl;
    }
};
int main(){
    Stack st;
    st.push(15);
    st.pop();
    st.top();
}