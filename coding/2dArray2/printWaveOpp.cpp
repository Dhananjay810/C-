#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter row and column : ";
    cin>>m>>n;
    int a[m][n];
    cout<<"enter value : ";
    for(int i=m-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i%2==0){
                cout<<a[i][j]<<" ";
            }
            else{
                cout<<a[i][n-j-1]<<" ";
            }
            
        }//cout<<endl;
    }
}