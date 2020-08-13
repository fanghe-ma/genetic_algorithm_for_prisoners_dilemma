#ifndef PLAYER_H_
#define PLAYER_H_
#include "matrix.h"
#include <iostream>

class Player{
   private:
      int n_layers; 
      int input_shape;
      int *layers_shape; //array of length = n_layers, e.g. [10, 4, 1]
      Matrix * layers_pts; //array of matrices
   public:
      Player(int l_input_shape, int num_layers, int *pt);
      Player();
      ~Player();
      float choose(Queue * qpt, int num) const;
      void update();
      friend std::ostream & operator<<(std::ostream & os, const Player & p1);

};

#endif
