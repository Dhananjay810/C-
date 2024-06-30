#include<iostream>
using namespace std;
void gun(){
    return; //khatam;
    cout<<"vello";
}
void fun(){
    cout<<"hello"<<endl;
    gun();
    fun(); //calling itself
}
int main(){
    fun();
}