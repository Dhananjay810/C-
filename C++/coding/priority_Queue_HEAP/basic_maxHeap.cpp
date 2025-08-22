#include<iostream>
#include<queue>
using namespace std;
int main(){
    // priority_queue<int> pq;  //max priority queue
    // pq.push(-8);
    // pq.push(9);
    // pq.push(18);
    // pq.push(0);
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // pq.push(100);
    // cout<<pq.top()<<endl;


    priority_queue< int, vector<int>, greater<int> > pq;  //min priority queue

    pq.push(-8);
    pq.push(9);
    pq.push(18);
    pq.push(0);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.push(100);
    cout<<pq.top()<<endl;
}