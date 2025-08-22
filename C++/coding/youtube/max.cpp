#include<iostream>
using namespace std;
int main(){
    int array[2][2
    ] = {{2,6},{5,10}};
    // int arr[2][2] = {{8,4},{9,7}};

    int max = array[0][0];
    for(int i=0; i<=1; i++){
        for(int j=0;j<=1;j++){
            if(max<array[j][i]){
                max=array[j][i];
            }

        }
    }
    cout<<max<<endl;
}