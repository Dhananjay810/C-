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
    int max=array[0][0];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(max<array[i][j]){
                max=array[i][j];
            }
            else{
                continue;
            }
        }


    }
    cout<<max;


}