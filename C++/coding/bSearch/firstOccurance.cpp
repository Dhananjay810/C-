#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int h;
    cin>>h;
    int low=0;
    bool k=false;
    int high=n-1;
      while(high>=low){
        int mid=(high+low)/2;
        if(a[mid]==h){
            if(a[mid-1]==h){
                high=mid-1;
            }
            else{
                cout<<mid;
                k=true;
                break;
            }
        }
        else if(a[mid]<h){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    for(int i=0; i<2; i++){
    while(high>=low){
        int mid=(high+low)/2;
        if(a[mid]==h){
            if(i==0){
            if(a[mid-1]==h){
                high=mid-1;
            }
            else{
                cout<<mid<<" ";
                k=true;
                break;
            }
        }
        else if(i==1){
             if(a[mid+1]==h){
                low=mid+1;
            }
            else{
                cout<<mid;
                k=true;
                break;
            }
        }
        }
        else if(a[mid]<h){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}
    if(k==false) cout<<"-1";
}