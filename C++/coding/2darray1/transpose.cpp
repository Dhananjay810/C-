#include<iostream>
using namespace std; 
int main(){
    int m,n;
    cout<<"enter no. of row and column : ";
    cin>>m>>n;
    int array[m][n];
    cout<<"enter value : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>array[i][j];
        }
    }
    cout<<endl;
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}