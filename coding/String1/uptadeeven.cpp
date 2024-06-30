#include<iostream>
using namespace std;
int main(){
    string n;
    cout<<"enter string : ";
    cin>>n;
    for(int i=0; n[i]!='\0'; i++){
        if(i%2==0){
            n[i]='a';
        }
    }
    cout<<n;
}