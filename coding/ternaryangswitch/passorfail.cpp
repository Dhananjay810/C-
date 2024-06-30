#include<iostream>
using namespace std;
int main(){
    int marks;
    cout<<"enter the marks obtained :";
    cin>>marks;
    // if(marks>33){
    //     cout<<"pass";
    // }
    // else{
    //     cout<<"fail";
    // }
    marks>33 ? cout<<"pass" : cout<<"fail";
}