#ifndef PLAYER_H_
#define PLAYER_H_
#include "matrix.h"
#include <iostream>

class Player{
   private:
      static int n_layers;
      static int layers_shape[n_layers];
      Matrix * layer_pts;
   public:
      Player(int input_shape = 40);
      ~Player();
      float choose(Queue * q1, 
                   Queue * q2, 
                   Queue * q3, 
                   Queue * q4) const;
      void update();
      friend std::ostream & operator<<(std::ostream & os, const Player & p1);

};

#endif
