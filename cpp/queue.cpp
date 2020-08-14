#include "queue.h"
#include <iostream>

Queue::Queue(int a){
   num_items = a;
   pt = new float[num_items];
   std::cout << "queue at: " << pt << " created" << std::endl;
   for(int i = 0; i < num_items; i++){
      pt[i] = 0;
   }
}

Queue::~Queue(){
   std::cout << "queue at: " << pt << " destroyed" << std::endl;
   delete [] pt;
}

void Queue::shift(float a){
   for(int i = 0; i < num_items - 1; i++){
      pt[i] = pt[i+1];
   }
   pt[num_items - 1] = a;
}

float & Queue::operator[](int i){
   return pt[i];
}

const float & Queue::operator[](int i)const{
   return pt[i];
}

Queue Queue::operator=(const Queue & q){
   if(pt == q.pt){
      return *this;
   }
   delete [] pt;
   num_items = q.num_items;
   for(int i = 0; i < num_items; i++){
      pt[i] = q.pt[i];
   }
   return *this;
}


std::ostream & operator<<(std::ostream & os, const Queue & q1){
   os << "[";
   char delim[] = ", ";
   for(int i = 0; i < q1.num_items; i++){
      os << q1[i] << (i == q1.num_items - 1 ? "" : delim);
   }
   os << "]"; 
   return os;
}
