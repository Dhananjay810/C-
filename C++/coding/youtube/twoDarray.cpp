#include<iostream>
using namespace std;
int main(){
    // int array[3][3] = {{4,5},{5,4},{1,8}};
    // for(int i=0; i<=2; i++){
    //     for(int j=0; j<=2;j++){
    //         cout<<array[j][i]<<" ";
    //     }
    //     cout<<endl;

    // }

    int i,j;
    cout<<"enter row and column : ";
    cin>>i>>j;
    cout<<"enter the element : ";
    int array[i][j];
    for(int m=0; m<=i-1; m++){
        for(int n=0; n<=j-1; n++){
            cin>>array[i][j];

        }
    }
    



}