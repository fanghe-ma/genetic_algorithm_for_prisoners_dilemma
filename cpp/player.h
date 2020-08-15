#ifndef PLAYER_H_
#define PLAYER_H_
#include "matrix.h"
#include <iostream>

class Player{
   private:
      int n_layers; 
      int input_shape;
      int *layers_shape; //array of length = n_layers, e.g. [10, 4, 1]
      float mutation_factor;
      Matrix * layers_pts; //array of matrices
      Matrix * bias_pts;

   public:
      Player(int l_input_shape, int num_layers, int *pt, float factor = 0.5);
      Player();
      ~Player();
      float choose(const Queue * qpt, int num) const;
      void update();
      friend std::ostream & operator<<(std::ostream & os, const Player & p1);

};

#endif
