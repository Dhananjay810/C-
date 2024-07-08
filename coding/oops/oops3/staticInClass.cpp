#include<iostream>
using namespace std;

class Bike{
    public:
    static int noOfBikes; // static Variable
    int tyreSize;
    int engineSize;

    //constructor
    Bike(int tyreSize,int engineSize){
        this->tyreSize=tyreSize;
        this->engineSize=engineSize;
    }
};

void print(){
    static int a=10;
    cout<<a<<endl;
    a++;
}

static void inc(){
    Bike::noOfBikes++;
}

//static variable assigning;
int Bike::noOfBikes=10;

int main(){
    // print();
    // print();
    // print();

    Bike honda(18,125);
    cout<<honda.noOfBikes<<endl;
    inc();
    cout<<honda.noOfBikes;

}