#pragma once
#include "Soldier.hpp"

class FootCommander: public Soldier
{
    public:
    FootCommander(int p, int h=150, int d=20): Soldier(h,d,p){}
    
    void attack(std::vector<std::vector<Soldier*>> s, std::pair<int,int> dest);
};
