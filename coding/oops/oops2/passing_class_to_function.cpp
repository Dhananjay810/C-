#include<iostream>

class Player{
    private:
    int score;
    int health;

    public:

    //setter

    void setHealth(int health){
        this->health=health;
    }

    void setScore(int score){
        this->score=score;
    }

    //getter

    int getScore(){
        return score;
    }

    int getHealth(){
        return health;
    }
};

//passing class to a function

int sumScore(Player a, Player b){
    return (a.getScore()+b.getScore());
}

//class return type function

Player healthy(Player a,Player b){
    if(a.getHealth()>b.getHealth()) return a;
    return b;
}

using namespace std;
int main(){

    Player harsh;
    harsh.setScore(50);
    harsh.setHealth(100);


    Player raghav;

    raghav.setScore(500);
    raghav.setHealth(250);

    cout<<sumScore(harsh,raghav)<<"\n";

    Player sanket;
    
    sanket = healthy(harsh,raghav);

    cout<<sanket.getHealth()<<"\n";

    cout<<harsh.getHealth()<<"\n";
    cout<<harsh.getScore()<<"\n";

    // Dynamic memory allocation

    Player *urvi = new Player;

    // Method of asigning value to data member
    //met-1

    Player urviObject=*urvi;
    urviObject.setHealth(784512);
    cout<<urviObject.getHealth()<<endl;

    //met-2

    (*urvi).setHealth(8748);
    cout<<(*urvi).getHealth()<<endl;

    //met-3

    urvi->setHealth(7845);
    cout<<urvi->getHealth()<<endl;


}