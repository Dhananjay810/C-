#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    // int low=0;
    // int high=n-1;
    // bool flag = false;
    // while(high>=low){
    //     int mid=low+(high-low)/2;
    //     if(mid*mid==n){
    //         cout<<"YES";
    //         flag=true;
    //         break;
    //     }
    //     else if(mid*mid>n) high=mid-1;
    //     else low=mid+1;
    // }
    // if(flag==false) cout<<"FALSE";
    int root=sqrt(n);
    if(root*root==n) cout<<"true";
    else cout<<"false";
}