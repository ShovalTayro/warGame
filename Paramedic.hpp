#pragma once
#include "Soldier.hpp"
#include <vector>

class Paramedic: public Soldier
{
    public:
    Paramedic(int p, int h=100, int d=50): Soldier(h,d,p){}
    void attack(std::vector<std::vector<Soldier*>> s, std::pair<int,int> dest);
};