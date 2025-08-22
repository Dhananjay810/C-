#include<iostream>
using namespace std;

class Bike{
    public:
    int tyreSize;
    int engineSize;


    // // default constructor
    // Bike(){
    //     cout<<"Constructor call hua!\n";
    // }

    // parameterised constructor
    Bike(int tyreSize,int engineSize){
        this->engineSize=engineSize;
        this->tyreSize=tyreSize;
        cout<<"Constructor call hua!\n";
    }


    //destructor function
    ~Bike(){
        cout<<"destructor call hua!\n";
    }

};

int main(){

    Bike pulsar(20,220);
    Bike apache(20,160);
    Bike honda(15,125);
    
    bool flag=true;
    if(flag==true){
        Bike yamaha(25,300);
        cout<<yamaha.engineSize<<" "<<yamaha.tyreSize<<endl;
    }

    cout<<pulsar.engineSize<<" "<<pulsar.tyreSize<<endl;
    cout<<apache.engineSize<<" "<<apache.tyreSize<<endl;
    cout<<honda.engineSize<<" "<<honda.tyreSize<<endl;
}