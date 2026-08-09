#include<iostream>
using namespace std;

class A{
private:
    void show(){
        cout<<"A ka private"<<endl;
    }

protected:
    void show1(){
        cout<<"A ka protected"<<endl;
    }

public:
    void show2(){
        cout<<"A ka public"<<endl;
    }
};

class B: private A{
public:
    void show(){
        cout<<"a ka protected but B ka public"<<endl;
    }
};

int main(){

    B b;
    b.show();

}