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
    int high=n-1;
    while(high>=low){
        int mid=(high+low)/2;
        if(a[mid]==h){
            cout<<a[mid-1];
            break;
        }
        else if(a[mid]<h){
            if(a[mid+1]>h){
                cout<<a[mid];
                break;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(a[mid-1]<h){
                cout<<a[mid-1];
                break;
            }
            else{
                high=mid-1;
            }
        }
    }
}