#include "doctest.h"
#include <stdexcept>
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <iostream>

using namespace std;
using namespace WarGame;

//make board and tests on the board
Board myGame(10, 10);


TEST_CASE("Test put soldiers on board"){
    // put player 1 commanders

    CHECK_NOTHROW((myGame[{0,4}] = new FootCommander(1)));
    CHECK_NOTHROW((myGame[{0,5}] = new ParamedicCommander(1)));
    CHECK_NOTHROW((myGame[{0,6}] = new SniperCommander(1)));

    //put 10 soldiers in front of the commanders - sniper paramedic footsoldier

    for (int i = 0; i < 10; ++i) {
        if ((i % 3) == 0) {
            CHECK_NOTHROW((myGame[{1, i}] = new Sniper(1)));
        }

        if ((i % 3) == 1){
            CHECK_NOTHROW((myGame[{1, i}] = new Paramedic(1)));
        }

        if ((i % 3) == 2) {
            CHECK_NOTHROW((myGame[{1, i}] = new FootSoldier(1)));
        }
    }

    // put player 2 commanders
    CHECK_NOTHROW((myGame[{9,4}] = new FootCommander(2)));
    CHECK_NOTHROW((myGame[{9,5}] = new ParamedicCommander(2)));

    //put 10 soldiers in front of the commanders - sniper paramedic footsoldier
    for (int i = 0; i < 10; ++i) {
        if ((i % 3) == 0) {
            CHECK_NOTHROW((myGame[{8, i}] = new Sniper(2)));
        }

        if ((i % 3) == 1) {
            CHECK_NOTHROW((myGame[{8, i}] = new Paramedic(2)));
        }

        if ((i % 3) == 2) {
            CHECK_NOTHROW((myGame[{8, i}] = new FootSoldier(2)));
        }
    }
}



TEST_CASE("check wrong moves"){ 

    CHECK_THROWS((myGame.move(1, { 0,2 }, Board::MoveDIR::Up))); // there is no soldier
    CHECK_THROWS((myGame.move(2, { 0,6 }, Board::MoveDIR::Down))); // there is no soldier
    CHECK_THROWS((myGame.move(2, { 9,5 }, Board::MoveDIR::Down))); // there is no soldoer.
    CHECK_THROWS((myGame.move(2, { 9,4 }, Board::MoveDIR::Up))); // there is no soldoer.
    CHECK_THROWS((myGame.move(2, { 1,4 }, Board::MoveDIR::Up))); // not belong to player 2.
    CHECK_THROWS((myGame.move(1, { 8,3 }, Board::MoveDIR::Down))); // not belong to player 1.
    CHECK_THROWS((myGame.move(1, { 4,0 }, Board::MoveDIR::Up))); // no soldier.
    CHECK_THROWS((myGame.move(2, { 3,9 }, Board::MoveDIR::Down))); // no soldier.
    CHECK_THROWS((myGame.move(1, { 5,1 }, Board::MoveDIR::Right))); // no soldier.
    CHECK_THROWS((myGame.move(2, { 6,7 }, Board::MoveDIR::Left))); // no soldier.
    CHECK_THROWS((myGame.move(1, { 0,3 }, Board::MoveDIR::Down))); //out of the board.
    CHECK_THROWS((myGame.move(2, { 9,6 }, Board::MoveDIR::Up))); // out of the board.
    CHECK_THROWS((myGame.move(1, { 0,6 }, Board::MoveDIR::Down))); //out of the board.
    CHECK_THROWS((myGame.move(1, { 1,0 }, Board::MoveDIR::Left))); // out of the board.
    CHECK_THROWS((myGame.move(2, { 1,9 }, Board::MoveDIR::Left))); // out of the board.
    CHECK_THROWS((myGame.move(1, { 2,8 }, Board::MoveDIR::Up))); // out of the board
}

void player1();
void player2();

TEST_CASE("Play game"){

    bool has_soldiers = true;
    while (true){
        CHECK_NOTHROW(has_soldiers = myGame.has_soldiers(1));
      //if player 1 have soldiers play
        if (has_soldiers) {
            CHECK_NOTHROW(player1());
        }

        else break;

        CHECK_NOTHROW(has_soldiers = myGame.has_soldiers(2));
       //if player 2 have soldiers -play
        if (has_soldiers) {
            CHECK_NOTHROW(player2());
        }

        else break;
    }

    CHECK(myGame.has_soldiers(1));
    CHECK(!myGame.has_soldiers(2));
}

void player1(){
    static bool on_commander = false;
    static Board::MoveDIR dir = Board::MoveDIR::Up;
    //move the soldiers and then the commanders
    if(!on_commander){
        for (int i = 0; i < 10; ++i) { 
            //  move line of  up if there is a soldier
            if(myGame[{1,i}] != nullptr){
                myGame.move(1,{1,i}, Board::MoveDIR::Up);
                return;
            }
        }
        on_commander = true;
        player1();
    } 
    else {
        if (dir == Board::MoveDIR::Up){
            for (int i = 4; i < 7; ++i) {
                if (myGame[{0, i}] != nullptr) {
                    myGame.move(1, {0, i}, dir);
                    return;
                }
            }
            dir = Board::MoveDIR::Down;
            player1();
        } 
        else {
            for (int i = 4; i < 7; ++i) {
                if (myGame[{1, i}] != nullptr) {
                    myGame.move(1, {1, i}, dir);
                    return;
                }
            }
            dir = Board::MoveDIR::Up;
            player1();
        }
    }
}

void player2(){
    for (int i = 8; i > 2; --i) { 
        for (int j = 0; j < 10; ++j) {
            if(myGame[{i,j}] != nullptr){
                myGame.move(2,{i,j}, Board::MoveDIR::Down);
                return;
            }
        }
    }
}



Board myGame2(5, 5);

TEST_CASE("Test put soldiers on board") {

    // put player 1 commanders
    CHECK_NOTHROW((myGame[{0, 1}] = new FootCommander(1)));
    CHECK_NOTHROW((myGame[{0, 2}] = new SniperCommander(1)));

    //put  soldiers in front of the commanders - sniper  footsoldier paramedic
    for (int i = 0; i < 5; ++i) {
        if ((i % 3) == 0) {
            CHECK_NOTHROW((myGame[{1, i}] = new Sniper(1)));
        }

        if ((i % 3) == 1) {
            CHECK_NOTHROW((myGame[{1, i}] = new FootSoldier(1)));
        }

        if ((i % 3) == 2) {
            CHECK_NOTHROW((myGame[{1, i}] = new Paramedic(1)));
        }
    }

    //put  soldiers in front of the  - sniper footsoldier paramedic 

    for (int i = 0; i < 5; ++i) {
        if ((i % 3) == 0) {
            CHECK_NOTHROW((myGame[{4, i}] = new Sniper(2)));
        }
        if ((i % 3) == 1) {
            CHECK_NOTHROW((myGame[{4, i}] = new FootSoldier(2)));
        }

        if ((i % 3) == 2) {
            CHECK_NOTHROW((myGame[{4, i}] = new Paramedic(2)));
        }
    }
}

//game snipers against only paramedics
Board myGame3(4, 4);

TEST_CASE("Test put soldiers on board") {
    //put  soldiers only snipers
    for (int i = 0; i < 4; ++i) {
        CHECK_NOTHROW((myGame3[{1, i}] = new Sniper(2)));
    }

    //put  soldiers in front of the  - sniper footsoldier paramedic 
    for (int i = 0; i < 4; ++i) {
        CHECK_NOTHROW((myGame3[{3, i}] = new Paramedic(1)));
    }
}

void player1();
void player2();

TEST_CASE("Play game") {
    bool has_soldiers = true;
    while (true) {
        CHECK_NOTHROW(has_soldiers = myGame3.has_soldiers(1));
        //if player 1 have soldiers play
        if (has_soldiers) {
            for (int i = 0; i < 4; i++){
                    if(myGame3[{3,i}] != nullptr){
                        myGame3.move(1,{3,i}, Board::MoveDIR::Down);
                        return;
                    }
            }
        }

        else break;

        CHECK_NOTHROW(has_soldiers = myGame3.has_soldiers(2));
        //if player 2 have soldiers -play
        if (has_soldiers) {
            for (int i = 0; i < 4; i++){
                if(myGame3[{1,i}] != nullptr){
                    myGame3.move(2,{1,i}, Board::MoveDIR::Up);
                    return;
                }
            }
        }
        else break;
    }

    CHECK(!myGame3.has_soldiers(1));
    CHECK(myGame3.has_soldiers(2));
}
