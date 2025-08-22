#include<iostream>
using namespace std;
int main(){
    int n=4;
    for(int i=1; i<=n+n-1; i++){
        for(int j=1; j<=n+n-1; j++){
        if(i<=n && (j<=n-i || j>=n+i)){
            cout<<"# ";
        }
        else if(i>=n+1 && (j<=i-n || j>=3*n-i)){
            cout<<"# ";
        }
        else{
            cout<<"* ";
        }
        }
        cout<<endl;
    }
    // for(int i=1; i<=n-1; i++){
    //     for(int j=1; j<=n+n-1; j++){
    //         if(j>n-1 || j){
    //             cout<<"  ";
    //         }
    //         else{ cout<<"* ";}
    //     }
    //     cout<<endl;
    // }
}