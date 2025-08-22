#include<iostream>
using namespace std;

class A{
    int a_ka_private=10;

    public:
    //friend function
    friend void show(A &a);
};

void show(A &a){
    cout<<a.a_ka_private<<endl;
}

int main(){
    A a;
    show(a);

}