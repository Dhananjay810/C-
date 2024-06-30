#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter no. of row and column of 1st array : ";
    cin>>m>>n;
    int array1[m][n];
    cout<<"enter value to 1st array : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>array1[i][j];
        }
    }
    int a,b;
    cout<<"enter no. of row and column of 2nd array : ";
    cin>>a>>b;
    int array2[a][b];
    cout<<"enter value to 2nd array : ";
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cin>>array2[i][j];
        }
    }
    int c,d;
    if(m<=a){
         c=m;
    }
    else {
     c=a;
        }
        if(n<=b){
         d=n;
    }
    else {
     d=b;
        }


    int array3[c][d];
    
    for(int i=0; i<c; i++){
        for(int j=0; j<d; j++){
            array3[i][j]=array1[i][j]+array2[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<array3[i][j]<<" ";
        }
        cout<<endl;
    }
    


}
