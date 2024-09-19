#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    int si=q.size();
    int k=5;
    for(int i=0; i<q.size(); i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
    stack<int> s;
    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }
    int f=q.size();
    while(s.size()>0){
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<f; i++){
        int l=q.front();
        q.pop();
        q.push(l);
    }
    for(int i=0; i<si; i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}