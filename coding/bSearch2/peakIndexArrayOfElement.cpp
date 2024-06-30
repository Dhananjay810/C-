#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    int low=0;
    int high=n-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
            cout<<mid;
            break;
        }
        else if(a[mid]<a[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}