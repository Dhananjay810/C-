#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,5,1,5,3,8,9,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    int result=0;
    for(int i=0; i<n; i++) result = result ^ arr[i];
    int temp=result;

    int k=0;
    while(true){
        if((temp & 1)==1) break;
        temp = temp >> 1;
        k++;
    }
    int r=0;
    for(int i=0; i<n; i++){
        if((arr[i] >> k)&1==1) r ^= arr[i];
    }
    cout<<r<<" ";
    result = r^result;
    cout<<result;
}