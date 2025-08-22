#include<iostream>
#include<queue>
using namespace std;
void display(queue<int>& q){
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
    int n=q.size();
    display(q);
    for(int i=0; i<n; i++){
        int a=q.front();
        q.pop();
        if(i%2!=0) q.push(a);
    }
    display(q);
}