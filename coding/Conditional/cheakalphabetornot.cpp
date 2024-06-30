#include<iostream>
using namespace std;
int main(){
    char x; //character is @ 1,3,a,S,!,#
    cout<<"enter te charecater :";
    cin>>x;
    int ascii = (int)x;
    if(ascii>=97 &&ascii<=122){
        cout<<"given chracter is lower case alphabet";
    }
    if(ascii>=65 && ascii<=90){
        cout<<"given chracter is upper case alphabet";
    }
    else{
        cout<<"not an alphabet";
    }

}