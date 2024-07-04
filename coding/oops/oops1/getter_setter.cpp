#include<iostream>
using namespace std;

class calulator{
    private:
    int a;
    int b;

    public:
    //setter

    void setA(int aa){ a=aa;}
    void setB(int bb){ b=bb; }


    //getter

    int add(){
        return a+b;
    }
    int sub(){
        return a-b;
    }
    int mul(){
        return a*b;
    }

    void getA(){
        cout<<"a is: "<<a<<endl;;
    }

    void getB(){
        cout<<"b is: "<<b<<endl;
    }

};

using namespace std;
int main(){

    calulator calci;

    calci.setA(15);
    calci.setB(5);

    calci.getA();
    calci.getB();

    cout<<calci.add()<<" "<<calci.sub()<<" "<<calci.mul();

}