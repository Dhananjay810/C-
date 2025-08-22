#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={10,9,8,7,4,70,60,50};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    int y=0;
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            arr[y]=pq.top();
            y++;
            pq.pop();
        }
    }
    for(int i=y; i<n; i++){
        arr[i]=pq.top();
        pq.pop();
    }
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}