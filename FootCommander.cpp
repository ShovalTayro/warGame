#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <math.h>
#include <iostream>
#include <vector>
#include <stdexcept>
 
using namespace std;
void FootCommander::attack(vector<vector<Soldier*>> &board, pair<int,int> source){
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

    //wake up all the footsoldiers
    pair<int,int> location(0,0);
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            Soldier* temp = board[i][j];
            if(temp != nullptr && temp->getPlayerNum() == board[source.first][source.second]->getPlayerNum() && dynamic_cast<FootSoldier*>(temp)){
                location.first = i;
                location.second = j;
                temp->attack(board, location);
            }
        }        
    }
}