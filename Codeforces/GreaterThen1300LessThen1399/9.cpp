#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int y=n*n;
    int a=1;
    int b=y;
    int t[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j%2==0){
                t[i][j]=a;
                a++;
            }
            else{
                t[i][j]=b;
                b--;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0 ;j<n; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

}