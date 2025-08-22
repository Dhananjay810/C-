#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a no. : ";
    cin>>n;
    int count=0;
    int x;
    int a=n;
    while(n>0){
        x=n%10;
        n=n/10;
        count=count+x;
        
    }
    if(a==0){
        cout<<"0";
    }
    else{
        cout<<count<<endl;
    }

}