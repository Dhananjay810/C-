#include<iostream>
using namespace std;
int prime(int u[] , int n){
    int f,g=0;
    for(int i=0; i<n; i++){
        for(int j=2; j<u[i]; j++){
            f=u[i]%j;
            if(f != 0){
                g++;

            }
            if(
                g == u[i]-2
            ){
                cout<<u[i]<<" ";
            }
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
    int y = prime(array,n);

}