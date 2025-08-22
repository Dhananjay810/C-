#include<iostream>
using namespace std;

class Gun{
    public:
    int bullet;
    int damage;
};

class Player{
    private:
    class Helmet{
        int hp;
        int level;

        public:

        int getHp(){
            return hp;
        }
        int getLevel(){
            return level;
        }

        void setHp(int hp){
            this->hp=hp;
        }
        void setLevel(int level){
            this->level=level;
        }
    };
    int score;
    int health;
    Gun gun;
    Helmet helmet;

    

    public:

    

    Gun getGun(){
        return gun;
    }

    int getScore(){
        return score;
    }

    int getHealth(){
        return health;
    }

    void setScore(int score){
        this->score=score;
    }

    void setHealth(int health){
        this->health=health;
    }

    void setGun(Gun gun){
        this->gun=gun;
    }

    //helmet

    void setHelmet(int level){
        Helmet *helmet = new Helmet;
        helmet->setLevel(level);
        int health;
        if(level==1) health=200;
        else if(level==2) health=350;
        else if(level==3) health=600;
        else cout<<"invalid level"<<endl;

        helmet->setHp(health);

        this->helmet=*helmet;
    }

    void getHelmet(){
        cout<<helmet.getHp()<<" "<<helmet.getLevel()<<endl;
    }
};



using namespace std;
int main(){

    Player harsh;
    harsh.setHealth(500);
    harsh.setScore(5000);

    Player raghav;
    raghav.setScore(600);
    raghav.setHealth(5470);

    Gun *ak47=new Gun;
    Gun *rifel=new Gun;

    ak47->bullet=800;
    ak47->damage=50;

    rifel->bullet=900;
    rifel->damage=100;

    harsh.setGun(*ak47);
    raghav.setGun(*rifel);    

    harsh.setHealth(1);
    raghav.setHelmet(2);

    Gun abc;
    abc=raghav.getGun();
    cout<<abc.bullet<<" "<<abc.damage<<endl;

    raghav.getHelmet();
    
    
}