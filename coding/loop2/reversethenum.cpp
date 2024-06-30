#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    int count=0;
    int r=0;
    while(n>0){
        r=r*10;
                count=n%10;
        r=r+count;
                n=n/10;       
    }
    cout<<r<<endl;
}