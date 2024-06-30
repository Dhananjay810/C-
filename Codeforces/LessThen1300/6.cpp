#include<iostream>
using namespace std;
int main(){
    int a[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }
    int b[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(a[i][j]%2!=0){
                if(b[i][j]==1) b[i][j]=0;
                else b[i][j]=1;
                if(b[i+1][j]==1 && i!=2) b[i+1][j]=0;
                else if(b[i+1][j]==0 && i!=2) b[i+1][j]=1;
                if(b[i][j+1]==1 && j!=2) b[i][j+1]=0;
                else if(b[i][j+1]==0 && j!=2) b[i][j+1]=1;
                if(b[i-1][j]==1 && i!=0) b[i-1][j]=0;
                else if(b[i-1][j]==0 && i!=0) b[i-1][j]=1;
                if(b[i][j-1]==1 && j!=0) b[i][j-1]=0;
                else if(b[i][j-1]==0 && j!=0) b[i][j-1]=1;
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }
}