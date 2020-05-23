#pragma once
#include <vector>

class Soldier{

    protected:
    int health;
    int damage;
    int playerNum;
    int maxHealth;
    //location

    public:
    Soldier(int h, int d, int p): health(h), damage(d), playerNum(p), maxHealth(h){}
   
    int getHealth(){ 
        return health;
    }

    void setHealth(int h){
        health = h;
    }

    int getDamage(){
        return damage;
    }

    int getPlayerNum(){
        return playerNum;
    }

    int getMaxHealth(){
        return maxHealth;
    }

    virtual void attack(std::vector<std::vector<Soldier*>> board, std::pair<int,int> source) = 0;
};