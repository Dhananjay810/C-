#include<iostream>
using namespace std;
int main(){
    int x[7]; //= {1,2,3,5,5,6,4}; // 0 1 2 3 4 5 6

    //taking input the value
    for(int i=0
    ; i<=6; i++){
        cin>>x[i];
    }
    // x[7]=6;
    // x[6]=616;
    // x[5]=663;
    // x[4]=665;
    // x[3]=666;
    // x[2]=668;
    // x[1]=663;
    // printing
    for(int i=0; i<=6; i++){
        cout<<2*x[i]<<" ";
    }
    
    

    // cout<<x[4];
}