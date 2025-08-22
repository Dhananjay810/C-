#include<iostream>
using namespace std;
int main(){
    float marks;
    cout<<"marks obtained :";
    cin>>marks;
    if(marks >= 90 && marks <= 100){
        cout<<"Grade A";
    }
    if(marks >= 80 && marks <= 90){
        cout<<"Grade B";
    }
    if(marks >= 70 && marks <= 80){
        cout<<"Grade C";
    }
   if(marks <= 70){
       cout<<"Fail";
   }
}