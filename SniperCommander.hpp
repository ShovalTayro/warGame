#pragma once
#include "Soldier.hpp"
#include <vector>

class SniperCommander: public Soldier
{
    public:
    SniperCommander(int p, int h=120, int d=100): Soldier(h,d,p){}

    void attack(std::vector<std::vector<Soldier*>> board, std::pair<int,int> source);
};