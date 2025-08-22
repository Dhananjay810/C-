#include<iostream>
using namespace std;

class Bike{
    public:
    int tyreSize;
    int engineSize;

    Bike(int tS,int eS) : tyreSize(tS), engineSize(eS){}
    Bike(int tS) : tyreSize(tS),engineSize(150){}
    Bike() : tyreSize(15),engineSize(100){}

};

int main(){

    Bike honde(12,125);
    Bike hero(10);
    Bike Fz;

    cout<<honde.engineSize<<" "<<honde.tyreSize<<endl;
    cout<<hero.engineSize<<" "<<hero.tyreSize<<endl;
    cout<<Fz.engineSize<<" "<<Fz.tyreSize<<endl;

}