#include "game.h"
#include <iostream>

Game::Game(){
   payoffs = {
      {{3, 3}, {1, 4}}, 
      {{4, 1}, {2, 2}}
   };
}

Game::~Game(){}

void Game::round(float c1, float c2){
   int choice1 = c1 > 0 ? 1 : -1;
   int choice2 = c2 > 0 ? 1 : -1;
   history[0].shift(payoffs[choice1 == 1 ? 1 : 0][choice2 == 1 ? 1 : 0][0]);
   history[1].shift(payoffs[choice1 == 1 ? 1 : 0][choice2 == 1 ? 1 : 0][1]);
   history[2].shift(choice1);
   history[3].shift(choice2);
}

std::ostream & operator<<(std::ostream & os, const Game & g){
   os << "payoffs: " << std::endl;
   for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++){
         os << "( ";
         os << g.payoffs[i][j][0] << ", ";
         os << g.payoffs[i][j][1] << " ) ";
      }
      os << "    ";
   }
   os << std::endl;

   os << "results history: " << std::endl;
   os << "player 1: " << history[0] << endl;
   os << "player 2: " << history[1] << endl;
   os << "strategies history: " << std::endl;
   os << "player 1: " << history[2] << endl;
   os << "player 2: " << history[3] << endl;
}
