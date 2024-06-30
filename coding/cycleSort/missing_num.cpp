#include<iostream>
using namespace std;
int main(){
    int arr[]={3,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<n){
        int idx=arr[i];
        if(i==idx || idx==n) i++;
        else swap(arr[i],arr[idx]);
    }
    for(int i=0; i<n; i++){
        if(i!=arr[i]){
            cout<<i;
            break;
        }
    }
}