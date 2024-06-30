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
    int arrays[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arrays[i][j]=array[j][i];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arrays[i][j]<<" ";
        }
        cout<<endl;
    }
}