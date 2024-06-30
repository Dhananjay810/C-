#include<iostream>
using namespace std;
int main(){
    string n;
    cout<<"enter string : ";
    cin>>n;
    for(int i=0; n[i]!='\0'; i++){
        if(n[i]=='a'){
            cout<<"a"<<" ";
        }
        else if(n[i]=='e'){
            cout<<"e"<<" ";
        }
        else if(n[i]=='i'){
            cout<<"i"<<" ";
        }
        else if(n[i]=='o'){
            cout<<"o"<<" ";
        }
        else if(n[i]=='u'){
            cout<<"u"<<" ";
        }
        else{
            continue;
        }
    }
}