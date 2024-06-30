#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. of element in squre matrix : ";
    cin>>n;
    int a[n][n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
    
    if(n%2==0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                int temp=a[i][j];
                a[i][j]=a[i][n-1-j];
                a[i][n-1-j]=temp;
            }
        }
    }
    else{
        //int h=n%2;
        for(int i=0; i<n; i++){
            for(int j=0; j<=n/2; j++){
                int temp=a[i][j];
                a[i][j]=a[i][n-1-j];
                a[i][n-1-j]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}