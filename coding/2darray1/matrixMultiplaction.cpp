#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. of elements in squre matrix : ";
    cin>>n;
     int a[n][n];
     cout<<"enter value of first matrix : ";
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
     }
     int b[n][n];
     cout<<"enter value of second matrix : ";
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>b[i][j];
        }
     }
     for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp = b[i][j];
            b[i][j]=b[j][i];
            b[j][i]=temp;
        }
     }
     int y[n][n];
    int k,sum=0;
     for(int i=0; i<n; i++){
        for(int l=0; l<n; l++){
        for(int j=0; j<n; j++){
            k=a[l][j]*b[l][j];
            sum=sum+k;
        }
    y[i][l]=sum;
    sum=0;
        }
     }
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<y[i][j]<<" ";
        }
        cout<<endl;
     }
     

}