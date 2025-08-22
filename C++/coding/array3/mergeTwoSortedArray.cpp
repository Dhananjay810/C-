#include <iostream>
using namespace std;
int sort(int a[], int b){
    for(int i=0; i<b; i++){
        for(int j=i; j<b; j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            else{
                continue;
            }
        }
    }
    for(int i=0; i<b;i++){
        cout<<a[i];
    }
}
int main(){
    int n,m;
    cout<<"enter no. of elements in 1st array : ";
    cin>>n;
    cout<<"enter no. of elements in 2nd array : ";
    cin>>m;
    int arr1[n],arr2[m];
    cout<<"enter value to 1st array : ";
    for(int i=0; i<n;i++){
        cin>>arr1[i];
    }
    cout<<"enter value to 2nd array : ";
    for(int i=0; i<m;i++){
        cin>>arr2[i];
    }
    int arr3[n+m];
    for(int i=0; i<n+m;i++){
        if(i<n){
            arr3[i]=arr1[i];
        }
        else if(i>=n && i<m+n){
            arr3[i]=arr2[i-n];
        }
    }

    int y=sort(arr3,m+n);
    // for(int i=0; i<n+m;i++){
    //     cout<<arr3[i];
    // }


}