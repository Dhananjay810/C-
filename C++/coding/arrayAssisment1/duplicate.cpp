#include<iostream>
using namespace std;
int duplicate(int a[],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i] == a[j] && i != j){
                cout<<"yes there is duplicate ";
            }break;

            // else{
            //     cout<<"no duplicate";
            // }
        }
    }
    // int h=0;
    // for(int i; i<n; i++){
    //     for(int j; j<n; j++){
    //         if(a[i] != a[j] && i != j){
    //             h++;
    //         }
    //     }
    // }
    // if(h == (n-1)*(n-2)){
    //     cout<<"no duplicate";
    // }
    return 0;
}
int main
(){
    int n; 
    cout<<"enter no. of element : ";
    cin>>n;
    int u[n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        cin>>u[i];
    }
    int k = duplicate(u,n);
}