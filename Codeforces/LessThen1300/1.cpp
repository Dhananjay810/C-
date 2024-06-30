#include<iostream>
using namespace std;
int main(){
    int n;
    //cout<<"enter n : ";
    cin>>n;
    int array[n][3];
    int array1[n];
    int array2[n];
    int array3[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>array[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            if(j==0){
            array1[i]=array[i][j];
            }
            else if(j==1){
                array2[i]=array[i][j];
            }
            else array3[i]=array[i][j];
        }
    }
    int u=0,v=0,w=0;
    for(int i=0; i<n;i++){
        u=u+array1[i];
    }
    for(int i=0; i<n;i++){
        v=v+array2[i];
    }
    for(int i=0; i<n;i++){
        w=w+array3[i];
    }
    if(u==0 && v==0 && w==0) cout<<"YES";
    else cout<<"NO";


}