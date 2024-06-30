#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size of squre matrix : ";
    cin>>n;
    int array[n][n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>array[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<array[j][i]<<" ";
        }
        cout<<endl;
    }

}