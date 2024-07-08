#include<iostream>
using namespace std;

class Bike{
    public:
    int tyreSize;
    int engineSize;

    Bike(int tS,int eS) : tyreSize(tS), engineSize(eS){}
};

int main(){
    Bike pulsar(20,150);

    cout<<pulsar.engineSize<<" "<<pulsar.tyreSize;
}