#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int low=0;
    int high=n;
    bool j=false;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(mid*mid==n){
            cout<<mid;
            j=true;
            break;
        }
        else if(mid*mid>n){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(j==false) cout<<high;
}