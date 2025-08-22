#include<iostream>
using namespace std;

class player{
public:
// data members
    int score;
    int health;

    //member function

    void showHealth(){
        cout<<"Health is:"<<health;
    }
};
using namespace std;
int main(){

player amit;
amit.score=10;
amit.health=66556;
cout<<amit.score;
cout<<" "<<amit.health<<endl;

amit.showHealth();


}