#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
        cin>>a[i][j];
        }
    }
    int count =0;
    for(int i=0; i<n; i++){
        bool flag1=false;
        bool flag2=false;
        bool flag3=false;
        bool flag4=false;
        for(int j=0; j<n; j++){
            if(a[i][1]==a[j][1] && i!=j){
                if(a[j][0]<a[i][0]) flag1=true;
                else if(a[j][0]>a[i][0]) flag2=true;
            }
        }
        if(flag1==true && flag2==true){
            for(int j=0; j<n; j++){
                if(a[i][0]==a[j][0] && i!=j){
                    if(a[j][1]<a[i][1]) flag3=true;
                    else if(a[j][1]>a[i][1]) flag4=true;
                }
            }
            if(flag3==true && flag4==true){
                count++;
            }
        }
        else continue;

    }
    cout<<count;
}