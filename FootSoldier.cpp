#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <math.h>

using namespace std;
void FootSoldier::attack(vector<vector<Soldier*>> &board, pair<int,int> source){
    int min = INT8_MAX;
    int dis;
    int row = 0;
    int col = 0;
    Soldier* target = nullptr;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            dis = sqrt(pow((i-source.first),2)+pow((j-source.second), 2));
            if(board[i][j] != nullptr && board[i][j]->getPlayerNum() != board[source.first][source.second]->getPlayerNum() && dis < min){
                min = dis;
                target = board[i][j];
                row = i;
                col = j;
            }
        }   
    }
    if(target != nullptr){
        if(target->getHealth() - board[source.first][source.second]->getDamage() <= 0 ){
            target = nullptr;
            board[row][col] = nullptr;
        } 
        else target->setHealth(target->getHealth() - board[source.first][source.second]->getDamage());
    }
}