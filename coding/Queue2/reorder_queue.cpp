#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void disp(queue<int>& q){
    int n = q.size();
    for(int i=0; i<n; i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    disp(q);
    stack<int> s;
    int n=q.size();
    for(int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }
    while(s.size()>0){
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<n/2; i++){
        q.push(q.front());
        q.pop();
    }
    disp(q);
    for(int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }
    disp(q);
    while(s.size()>0){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    disp(q);
}