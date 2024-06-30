#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the side of triangle : ";
    cin>>n;
    for(int i=1;i<=n; i++){
        for(int j=1; j<=2*n-1; j++){
            if(j<=n-i || j>=n+i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
        
        }
        for(int h=n+1; h<=2*n-1; h++){
            for(int u=1; u<=2*n-1; u++){
                if(u<=h-n || u>=3*n-h){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
            cout<<endl;
        }
        
    }
