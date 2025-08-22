#include<iostream>
using namespace std;
int main(){
    int arr[]={2,2,2,1,2,2,1,2,2,2};
    int k=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0,ans=0,count=0,odd=0;
    while(j<n){
        if(arr[j]%2!=0){
            odd++;
            count=0;
        }
        while(i<=j && odd==k){
            count++;
            if(arr[i]%2!=0) odd--;
            i++;
        }
        ans=ans+count;
        j++;
    }
    cout<<ans;
}