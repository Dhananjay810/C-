#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // //bubble sorting
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i-1; j++){
    //         if(a[j]>a[j+1]){
    //             swap(a[j],a[j+1]);
    //         }
    //     }
    // }
    //bubble sorting optimising
    for(int i=0; i<n; i++){
        bool flag=true;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag = false;
            }
        }
        if(flag==true) break;
    }
    for(int i=0; i<n; i++){cout<<a[i]<<" ";}
}