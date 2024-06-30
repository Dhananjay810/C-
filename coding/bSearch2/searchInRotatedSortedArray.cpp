#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int o;
    cin>>o;
    int low=0;
    int high=n-1;
    int idx=-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            idx=mid+1;
            break;
        }
        if(a[mid]<a[mid-1] && a[mid]<a[mid+1]){
            idx=mid;
            break;
        }
        else if(a[mid]<a[mid+1] && a[mid]>a[mid-1] && a[mid]>a[n-1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    int g=idx;
    int y=n-1;
    while(y>=g){
        int mid=g+(y-g)/2;
        if(a[mid]==o){
            cout<<mid;
            break;
        }
        else if(a[mid]<o) low=mid+1;
        else high=mid-1;
    }

}