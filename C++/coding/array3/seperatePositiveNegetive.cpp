#include<iostream>
using namespace std;
int sign(int a[], int n){
    int o=0;
    
    for(int u=0; u<n; u++){
        if(a[u]<0){
           cout<<a[u];
            
        }
    }
    cout<<" ";
    for(int u=0; u<n; u++){
        if(a[u]>0){
           cout<<a[u];
            
        }
    

}
}
int main(){
    int n; 
    cout<<"enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int y= sign(array,n);
}
