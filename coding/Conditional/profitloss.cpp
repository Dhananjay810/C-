#include<iostream>
using namespace std;
int main(){
    int SP,CP;
    cout<<"enter CP :";
    cin>>CP;
    cout<<"enter SP :";
    cin>>SP;
    if(SP>CP){
        int profit = SP-CP;
        cout<<"profit of :";
        cout<<profit;

    }
    if(SP<CP){
        int loss = CP -SP;
        cout<<"loss of :";
        cout<<loss;
    }
    if(SP==CP){
        cout<<"no profit no loss!";
    }
}