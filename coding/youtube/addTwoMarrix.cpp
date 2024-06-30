#include<iostream>
using namespace std;
int main(){
    int array[2][2
    ] = {{2,6},{5,8}};
    int arr[2][2] = {{8,4},{5,7}};

    //int add[2][2];
    int v;
    for(int i=0;i<=1; i++){
        for(int j=0; j<=1; j++){
            v = arr[j][i] + array[j][i];
            cout<<v<<" ";
        }
        cout<<endl;

        
    }
    // for(int i=0; i<=2; i++){
    //     for(int j=0; j<=2;j++){
    //         cout<<add[j][i]<<" ";
    //     }
    //     cout<<endl;

    // }

}