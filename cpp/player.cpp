#include "player.h"
#include "matrix.h"
#include <iostream>

Player::Player(int l_input_shape, int num_layers, int *pt){
   input_shape = l_input_shape;
   n_layers = num_layers;
   layers_shape = new int[n_layers];
   layers_pts = new Matrix[n_layers];
   for(int i = 0; i < n_layers; i++){
      layers_shape[i] = pt[i];
      layers_pts[i] = Matrix((i == 0 ? input_shape : layers_shape[i-1]), layers_shape[i]);
   }
}

Player::Player(){
   n_layers = 0;
   input_shape = 0;
   layers_shape = NULL;
   layers_pts = NULL;
}

Player::~Player(){
   delete [] layers_shape;
   delete [] layers_pts;
}

float Player::choose(Queue * qpt, int num) const{
   Matrix m(*qpt);
   for(int i = 1; i < num; i++){
      m = m.join(Matrix(qpt[i]));
   }
   for(int i = 0; i < n_layers; i++){
      m = m*layers_pts[i];
   }
   return m.pt[0];
}
void update(){
   
}
std::ostream & operator<<(std::ostream & os, const Player & p1);
