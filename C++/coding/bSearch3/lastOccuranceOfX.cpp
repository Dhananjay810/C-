#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int y;
    cin>>y;
    bool r=false;
    int low=0;
    int high=n-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(a[mid]==y){
            if(a[mid+1]==y){
                low=mid+1;
            }
            else {
                cout<<a[mid];
                r=true;
                break;
                }
        }
        else if(a[mid]<y) low=mid+1;
        else high=mid-1;
    }
    if(r==false){
        cout<<"-1";
    }
}