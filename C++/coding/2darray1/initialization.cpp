#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"enter no. of row and column : ";
    cin>>n>>m;
    int array[n][m];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>array[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    
}
