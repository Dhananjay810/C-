#include<iostream>
using namespace std;
int main(){
    int a[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>a[i][j];
        }
    }
    int x=0,y=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(a[i][j]==1){
                x=i+1;
                y=j+1;
                break;    
            }
        }
        if(x!=0 && y!=0){
            break;
        }
        else continue;
    }
    //cout<<x<<" "<<y<<" ";
    int u=x-3;
    int v=y-3;
    if(u<0) u=u*(-1);
    if(v<0) v=v*(-1);

    cout<<u+v;
}