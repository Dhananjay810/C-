#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int low=0;
    int high=n-1;
    int y=0;
    int idx=-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(a[mid]==y){
            if(a[mid+1]==y) low=mid+1;
            else{ 
                idx=mid;
                break;
                }
           
        }
        else if(a[mid]>y) high=mid-1;
        else low=mid+1;
    }
    cout<<n-idx-1;
}