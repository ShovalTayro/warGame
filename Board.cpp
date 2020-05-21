#include "Board.hpp"
#include<iostream>

using namespace std;
namespace WarGame{
    
    bool Board::has_soldiers(uint player_number) const{
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                Soldier* temp = board[i][j];
                if(temp != nullptr && temp->getPlayerNum() == player_number) return true;
            }   
        }
        return false;
    }

   Soldier*& Board::operator[](pair<int,int> location){
      return board[location.first][location.second];
   }
   
   Soldier* Board::operator[](pair<int,int> location) const{
       return board[location.first][location.second];
   }
   
   void Board::move(uint player_number, pair<int,int> source, MoveDIR direction){
       Soldier* temp = (*this)[source];
       if(temp == nullptr) throw invalid_argument("There is no soldier in this location");
       if(temp->getPlayerNum() != player_number) throw invalid_argument("This soldier belongs to the other player");

       //found the dest
       pair<int,int> dest;
       //up on the board 
       if(player_number == 1){
           cout<< "player 1: ";
           switch (direction)
           {
               case Up:
                    dest.first = source.first+1;
                    dest.second = source.second;
                    break;

                case Down:
                    dest.first = source.first-1;
                    dest.second = source.second;
                    break;  

                case Right:
                    dest.first = source.first;
                    dest.second = source.second-1;
                    break;

                case Left:
                    dest.first = source.first;
                    dest.second = source.second+1;
                    break;
              
                default:
                    break;
            }
            cout << dest.first << " " << dest.second <<endl;
       }
       //down on the board
       if(player_number == 2){
           cout<< "player 2: ";
           switch (direction)
           {
               case Up:
                    dest.first = source.first+1;
                    dest.second = source.second;
                    break;

                case Down:
                    dest.first = source.first-1;
                    dest.second = source.second;
                    break;  

                case Right:
                    dest.first = source.first;
                    dest.second = source.second+1;
                    break;

                case Left:
                    dest.first = source.first;
                    dest.second = source.second-1;
                    break;
              
                default:
                    break;
           }
           cout << dest.first << " " << dest.second <<endl; 
       }
       //check if the dest is on the board
       if(dest.first < 0 || dest.first > board.size()-1 || dest.second < 0 || dest.second > board[0].size()-1)
       throw out_of_range("The loction is out of range");
       
       (*this)[dest] = temp;
       temp->attack(board, dest);
    }
   

};