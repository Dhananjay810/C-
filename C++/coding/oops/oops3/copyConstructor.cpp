#include<iostream>
using namespace std;

class Bike{
    public:
    int tyreSize;
    int engineSize;

    
};

int main(){
    Bike b1;
    b1.engineSize=500;
    b1.tyreSize=25;

    cout<<b1.engineSize<<" "<<b1.tyreSize<<endl;

    

    Bike b2(b1); // copy consructor(deep copy)

    // b2=b1 -->shallow copy(not independent)

    cout<<b2.engineSize<<" "<<b2.tyreSize<<endl;

    b1.engineSize=50;
    b1.tyreSize=25;
    cout<<b1.engineSize<<" "<<b1.tyreSize<<endl;
    cout<<b2.engineSize<<" "<<b2.tyreSize<<endl;
}