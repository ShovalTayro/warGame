#pragma once
#include "Soldier.hpp"
#include <vector>

class ParamedicCommander: public Soldier
{
    public:
    ParamedicCommander(int p, int h=200, int d=100): Soldier(h,d,p){}
    
    void attack(std::vector<std::vector<Soldier*>> s, std::pair<int,int> dest);
};