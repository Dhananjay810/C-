#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={10,15,-8,45,52,100,-99,-18};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<pq.top();
}