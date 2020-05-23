#include "Paramedic.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
 
using namespace std;
void Paramedic::attack(vector<vector<Soldier*>> board, pair<int,int> source){
    int a = source.first;
    int b = source.second;

    //Up
    if(a > 0 && board[a-1][b] != nullptr){
        if(board[a-1][b]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a-1][b]->setHealth(board[a-1][b]->getMaxHealth());
    }
    //Up-Left *\*
    if(a > 0 && b > 0 && board[a-1][b-1] != nullptr){
        if(board[a-1][b-1]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a-1][b-1]->setHealth(board[a-1][b-1]->getMaxHealth());
    }
    //Up-Right */*
    if(a > 0 && b < board[0].size()-1 && board[a-1][b+1] != nullptr){
        if(board[a-1][b+1]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a-1][b+1]->setHealth(board[a-1][b+1]->getMaxHealth());
    }
    //Left
    if(b > 0 && board[a][b-1] != nullptr){
        if(board[a][b-1]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a][b-1]->setHealth(board[a][b-1]->getMaxHealth());
    }
    //Right
    if(b < board[0].size()-1  && board[a][b+1] != nullptr){
        if(board[a][b+1]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a][b+1]->setHealth(board[a][b+1]->getMaxHealth());
    }
    //Down-Left */*
        if(a < board.size()-1 && b > 0 && board[a+1][b-1] != nullptr){
        if(board[a+1][b-1]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a+1][b-1]->setHealth(board[a+1][b-1]->getMaxHealth());
    }
    //Down
    if(a < board.size()-1 && board[a+1][b] != nullptr){
        if(board[a+1][b]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a+1][b]->setHealth(board[a+1][b]->getMaxHealth());
    }
    //Down-Right *\*
    if(a < board.size()-1 && b < board[0].size()-1 && board[a+1][b+1] != nullptr){
        if(board[a+1][b+1]->getPlayerNum() == board[a][b]->getPlayerNum())
            board[a+1][b+1]->setHealth(board[a+1][b+1]->getMaxHealth());
    }
}