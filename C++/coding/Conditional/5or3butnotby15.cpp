#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"enter no. :";
    cin>>x;
    // if((x%3 == 0 || x%5 == 0) && x%15 != 0){
    //     cout<<"the no.is divisible by 5 or 3 but not by 15";
    //         }
    //         else{
    //             cout<<"not matching the condition";
    //         }
    if(x%5==0 || x%3==0){
        if(x%15!=0){
            cout<<"the no. is divisibe by 3 or 5 but not with 15";

        }
        else{
            cout<<"not matching condition";
        }
    }
    
}
