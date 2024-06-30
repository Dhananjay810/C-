#include<iostream>
using namespace std;
// int multiply(int a[][], int b[][], int w,int x,int y,int z){

// }
int main(){
    int m;
    cout<<"enter no. row in 1st matrix : ";
    cin>>m;
    int n;
    cout<<"enter no. cols in 1st matrix : ";
    cin>>n;
    int a;
    cout<<"enter no. row in 2nd matrix : ";
    cin>>a;
    int b;
    cout<<"enter no. cols in 2nd matrix : ";
    cin>>b;
    if(n==a){
        int a1[m][n];
        int a2[a][b];
        cout<<"enter value to 1st matrix : ";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>a1[i][j];
            }
        }
        cout<<"enter value to 2nd matrix : ";
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cin>>a2[i][j];
            }
        }
        //int y=multiply(a1,a2,m,n,a,b);
        //int sum=0,k;
        int res[m][b];
        for(int i=0; i<m; i++){
            for(int j=0; j<b; j++){
                res[i][j]=0;
                for(int u=0; u<a; u++){
                   res[i][j] += a1[i][u]*a2[u][j];
                }
                
            }
        }
        for(int i=0; i<m; i++){
        for(int j=0; j<b; j++){
            cout<<res[i][j]<<" ";

        }
        cout<<endl;
    }
    }
    else{
        cout<<endl<<"matrix can't get multiplied ";
    }
    
    

}