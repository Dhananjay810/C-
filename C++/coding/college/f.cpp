#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"enter its value : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int arr1[2];
    int y;
    cout<<"enter y : ";
    cin>>y;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==y && i<n-1){
                arr1[0]=i;
                arr1[1]=j;
            }
            else{
                continue;
            }
        }
    }
    cout<<arr1[0]<<" "<<arr1[1];
     
    

}