#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={1,4,8,3,7,5,9,9,9,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);

int maxa=INT_MIN;
int count=0;
int ans=0;
for(int i=0; i<n; i++){
    if(arr[i]>maxa){
        maxa=arr[i];
        count = 1;
    }
    else if(arr[i] == maxa) count++;


    ans=max(ans,count);
}
    cout<<ans;
}