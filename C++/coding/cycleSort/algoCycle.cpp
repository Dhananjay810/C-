// here iss some constraint 
// array must contain number such as [1,n] OR [0,n]

#include<iostream>  
using namespace std;
int main(){
    int arr[]={4,1,2,6,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k=0;
    while(k<n){
        int corr=arr[k]-1;
        if(k==corr) k++;
        else swap(arr[k],arr[corr]);
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}