#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={3,-4,-7,30,7,-9,2,1,6,-1};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    int ar[n-k+1];
    for(int i=0; i<n-k+1; i++){
        if(q.front()<i+k && q.front()>=i){
            ar[i]=arr[q.front()];
            if(q.front()==i) q.pop();
        }
        else ar[i]=0;
    }
    for(int i=0; i<n-k+1; i++) cout<<ar[i]<<" ";
}