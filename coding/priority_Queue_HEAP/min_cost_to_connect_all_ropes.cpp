#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={2,7,4,1,8};
    priority_queue<int, vector<int>, greater<int> > pq;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) pq.push(arr[i]);
    int cost=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        cost=cost+a+b;
        pq.push(a+b);
    }
    cout<<cost;
}