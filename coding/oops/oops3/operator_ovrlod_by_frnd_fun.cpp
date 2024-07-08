#include<iostream>
using namespace std;
class complex{
    public:
    int imaginary;
    int real;

    public:
    friend complex operator +(complex &c1,complex &c2);
};

complex operator +(complex &c1,complex &c2){
    complex c3;
    c3.imaginary=c1.imaginary+c2.imaginary;
    c3.real=c1.real+c2.real;
    return c3;
}

int main(){

    complex c1,c2;
    c1.imaginary=10;
    c1.real=5;
    c2.imaginary=2;
    c2.real=3;

    complex c3;
    c3=c1+c2;

    cout<<c3.real<<" "<<c3.imaginary<<endl;


}