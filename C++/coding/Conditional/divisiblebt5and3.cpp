#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter a no. :";
    cin>>a;
    if(a%5==0 && a%3!=0){ // if condition 1 is false the cmpiler not check condition 2  
        cout<<"divisible by 5 but not by 3";
    }
    if(a%5!=0 && a%3==0){
        cout<<"divisible by 3 but not by 5";
    }
    if(a%5==0 && a%3==0){
        cout<<"divisible by both 3 and 5";
    }
    
    
}