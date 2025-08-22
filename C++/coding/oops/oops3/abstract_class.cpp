#include<iostream>
using namespace std;

class a{
    public:
    int a;

    virtual void show(){
        cout<<"a_ka_show"<<endl;
    }
};

class b : public a{
    public:
    int b;

    void show(){
        cout<<"b_ka_show"<<endl;
    }
};

int main(){

    

}