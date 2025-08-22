#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. till what you want to check:";
            cin>>n;
    int i=1;
    while(i<=n){
        if(i%3==0){
            cout<<i<<endl;
        }
        i++;
    }        

}