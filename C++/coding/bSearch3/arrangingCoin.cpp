#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t=n;
    int row=1;
    // while(n>=0){
    //     int mid=row*(row+1)/2;
    //         if(mid<=t){
    //         row++;
    //     }
    //     else{
    //         cout<<row-1;
    //         break;
    //     }

    // }
    while(n>=0){
        if(row<=t){
            t=t-row;
            row++;
        }
        else{
            cout<<row-1;
            break;
        }
    }
}