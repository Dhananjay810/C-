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
    int low=0;
    int high=5;
    bool flag=false;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(a[mid]==y){
            cout<<"yes";
            flag=true;
            break;
        }
        else if(a[high]<y){
            low=low+5;
            high=high+5;
        }
        else if(a[mid]<y && mid<high) low=mid+1;
        else high=mid-1;
    }
    if(flag==false) cout<<"No";
}