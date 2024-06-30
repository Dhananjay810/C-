#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter side : ";
    cin>>n;
    int y=n-1;
    for(int u=1; u<=2*n-1; u++){
        cout<<u;
    }
    cout<<endl;
    for(int i=1; i<=y; i++){
        for(int j=1; j<=2*n-1; j++){
            if(j<=n-i || j>=n+i){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}