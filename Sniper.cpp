#include "Sniper.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
 
using namespace std;
void Sniper::attack(vector<vector<Soldier*>> &board, pair<int,int> source){
    Soldier* attacking = board[source.first][source.second];
    Soldier* target = nullptr;
    int maxLife = 0;
    int row;
    int col;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            //if we found a soldier that belong to the other player
            if(board[i][j] != nullptr && board[i][j]->getPlayerNum() != attacking->getPlayerNum()){
                //we search the soldier with the max life
                if(maxLife <= board[i][j]->getHealth()){
                    target = board[i][j];
                    maxLife = board[i][j]->getHealth();
                    row = i;
                    col = j;
                }
            }
        }
    }
    if(target != nullptr){
        if(target->getHealth() - attacking->getDamage() <= 0 ){
            target = nullptr;
            board[row][col] = nullptr;
        } 
        else target->setHealth(target->getHealth() - attacking->getDamage());
    }
}