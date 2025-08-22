#include<iostream>
using namespace std;;
int main(){
    int arr[]={11,13,17,23,29,31,7,5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int t=5;
    t=k*t;
    int sum=0;
    for(int i=0; i<k; i++) sum += arr[i];
    int i=1,j=k,count=0;
    if(sum>=t) count++;
    while(j<n){
        sum += arr[j];
        sum -= arr[i-1];
        if(sum>=t) count++;
        i++;
        j++;
    }
    cout<<count;
}