#include "player.h"
#include "matrix.h"
#include "queue.h"
#include <iostream>

Player::Player(int l_input_shape, int num_layers, int *pt, float factor){
   input_shape = l_input_shape;
   n_layers = num_layers;
   layers_shape = new int[n_layers];
   layers_pts = new Matrix[n_layers];
   bias_pts = new Matrix[n_layers];
   mutate_factor = factor;

   for(int i = 0; i < n_layers; i++){
      layers_shape[i] = pt[i];
      layers_pts[i] = Matrix((i == 0 ? input_shape : layers_shape[i-1]), layers_shape[i]);
      bias_pts[i] = Matrix(1, layers_shape[i]);
   }


}

Player::Player(){
   n_layers = 0;
   input_shape = 0;
   layers_shape = NULL;
   layers_pts = NULL;
   mutate_factor = 0;
}

Player::~Player(){
   delete [] layers_shape;
   delete [] layers_pts;
}
float Player::choose(const Queue * qpt, int num) const{
   Matrix m(*qpt);
   for(int i = 1; i < num; i++){
      m = m.join(Matrix(qpt[i]));
   }
   for(int i = 0; i < n_layers; i++){
      m = m * layers_pts[i] - bias_pts[i];
   }
   return m.pt[0];
}

void Player::update(){
   for(int i = 0; i < n_layers; i++){
      layers_pts[i] = layers_pts[i] + Matrix(layers_pts[i].xdims, layers_pts[i].ydims) * mutate_factor; 
      bias_pts[i] = layers_pts[i] + Matrix(bias_pts[i].xdims, bias_pts[i].ydims) * mutate_factor; 
   }
}

std::ostream & operator<<(std::ostream & os, const Player & p1){
   os << "player at: " << &p1 << std::endl;
   os << "number of layers: " << p1.n_layers << std::endl;
   os << "layers shape: ";
   for(int i = 0; i < p1.n_layers; i++){
      os << p1.layers_shape[i] << " ";
   }
   os << std::endl;
   os << "layers:  " << std::endl;
   for(int i = 0; i < p1.n_layers; i++){
      os << "weights " << i + 1 << ": " << std::endl << p1.layers_pts[i] << std::endl;
      os << "bias " << i + 1 << ": " << std::endl << p1.bias_pts[i] << std::endl;
   } return os;
}
