#include<iostream>
using namespace std;

class book{
    public:
    int price;
    int noofpage;
    char ch;

    int countBook(int a){
        if(price==a) return 1;
        else return 0;
    } 

    bool isBook(char c){
        if(c==ch) return true;
        return false;
    }

};

using namespace std;
int main(){

    book HarryPotter;

    HarryPotter.price=1255;
    HarryPotter.noofpage=89623;
    HarryPotter.ch='H';

    cout<<HarryPotter.countBook(1500)<<" "<<HarryPotter.isBook('H');


}