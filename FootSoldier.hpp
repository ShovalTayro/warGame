#pragma once
#include "Soldier.hpp"
#include <vector>

class FootSoldier: public Soldier
{
    public:
   FootSoldier(int p, int h=100, int d = 10): Soldier(h,d,p){}
  
   void attack(std::vector<std::vector<Soldier*>> s, std::pair<int,int> dest);
};
