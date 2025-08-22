#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=-1;
    int low=0;
    int high=n-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(a[mid]==mid){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    cout<<ans;
}