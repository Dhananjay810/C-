#include<iostream>
using namespace std;
int main(){
    int arr[]={1,1,1};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0,count=0,len=0;
    int sum=0;
    int pro=1;
    while(j<n){
        sum=sum+arr[j];
        pro=sum*(j-i+1);
        while(pro>=k){
            sum=sum-arr[i];
            i++;
            pro=sum*(j-i+1);
        }
        count=count+(j-i+1);
       // cout<<i<<" "<<j<<endl;
        j++;
    }
    cout<<count;
}