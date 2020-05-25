#pragma once
#include "Soldier.hpp"
#include <vector>

class ParamedicCommander: public Soldier
{
    public:
    ParamedicCommander(int p, int h=200, int d=100): Soldier(h,d,p){}
    
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
};