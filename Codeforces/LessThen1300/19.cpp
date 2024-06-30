#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n][2];
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>array[i][j];
        }
    }
    int array1[n+1];
    for(int i=0; i<n+1; i++){
        array1[i]=0;
    }
    for(int i=0; i<n+1; i++){
        array1[i+1]=(array1[i]-array[i][0])+array[i][1];
    }
    // for(int i=0; i<n+1; i++){
    //     array1[i+1]=(array1[i]-array[i][0])+array[i][1];
    // }
    // for(int i=0; i<n+1; i++){
    //     cout<<array1[i];
    // }
    int t=array1[0];
    for(int i=0; i<n+1; i++){
        if(array1[i]>t){
            t=array1[i];
        }
    }
    cout<<t;
}