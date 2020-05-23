#pragma once
#include "Soldier.hpp"
#include <vector>

class FootSoldier: public Soldier
{
    public:
   FootSoldier(int p, int h=100, int d = 10): Soldier(h,d,p){}
  
   void attack(std::vector<std::vector<Soldier*>> board, std::pair<int,int> source);
};
