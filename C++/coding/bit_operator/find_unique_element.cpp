#include<iostream>
using namespace std;
int main(){
    int arr[]={1,21,1,3,8,5,3,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int u=0;
    for(int i=0; i<n; i++){
        u=u^arr[i];
    }
    cout<<u;
}