#include<iostream>
using namespace std;
int main(){
    
   int n;
    cout<<" enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter value of element : ";
    for(int j=0; j<=n-1; j++){
        
        cin>>array[j];
    }
    int x;
    cout<<"enter x : ";
    cin>>x;
    int count=0;
    for(int i=0; i<=n-1; i++){
        if(array[i]>x) count++;
    }
    cout<<count;
    



}