#include<iostream>
using namespace std;
int main(){
    char gender;
    cout<<"enter gender :";
    cin>>gender;
    float amount;
    cout<<"enter amount :";
    cin>>amount;
    if(gender == 'F' && amount >= 5000){
        float balance = amount + 0.05*amount;
        cout<<"your final amount :";
        cout<<balance;
    }
    else{
        float BALANCE = amount + 0.02*amount;
        cout<<"your final amount is :";
        cout<<BALANCE;
    }
    return 0;
}