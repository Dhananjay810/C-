#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the side : ";
    cin>>n;
    for(int u=1; u<=2*n-1; u++){
        cout<<"*";
    }
    cout<<endl;

    int y=n-1;
    for(int i=1; i<=y; i++){
        for(int j=1; j<=2*n-1; j++){
            if(
                j<=n-i || j>=n+i
            ){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            

        }
        cout<<endl;
    }
    //  for(int h=y+1; h<=2*y-1; h++){
    //         for(int u=1; u<=2*n-1; u++){
    //             if(u<=h-n || u>=3*n-h){
    //                 cout<<"*";
    //             }
    //             else{
    //                 cout<<" ";
    //             }
    //         }
    //         cout<<endl;
    //     }
}