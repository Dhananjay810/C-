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
    bool flag=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==h){
            cout<<"true";
            flag=true;
            break;
        }
        else if(a[mid]>h) low=mid+1;
        else high=mid-1;
    }
    if(flag==false) cout<<"false";
}