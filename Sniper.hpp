#pragma once
#include "Soldier.hpp"
#include <vector>

class Sniper: public Soldier
{
    public:
    Sniper(int p, int h=100, int d=50): Soldier(h,d,p){}
    
    void attack(std::vector<std::vector<Soldier*>> board, std::pair<int,int> source);
};