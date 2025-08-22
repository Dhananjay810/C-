#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);

    // USING PREFIX SUM....

    // vector<int> v(n);
    // v[0]=arr[0];
    // for(int i=1; i<n; i++){
    //     v[i]=v[i-1]+arr[i];
    // }
    // int max=v[k-1];
    // int idx=2;
    // for(int i=k; i<n; i++){
    //     if(max<(v[i]-v[i-k])){
    //         max=(v[i]-v[i-k]);
    //         idx=i;
    //     }
    // }
    // for(int i=idx-k+1; i<=idx; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl<<"sum is "<<max;

    // USING SLIDING WINDOWS 

    int premax=0;
    for(int i=0; i<k; i++){
        premax=premax+arr[i];
    }
    int max=INT_MIN;
    max=premax;
    int i=1,j=k;
    int st=0;
    while(j<n){
        int sum=premax+arr[j]-arr[i-1];
        if(max<sum){
            max=sum;
            st=i;
        }
        premax=sum;
        i++;
        j++;
    }
    for(int a=st; a<st+k; a++){
        cout<<arr[a]<<" ";
    }
}