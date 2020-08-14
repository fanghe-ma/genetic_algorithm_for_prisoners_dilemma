#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>

class Queue{
   private:
      float * pt;
      int num_items;
      friend class Matrix;
      friend class Player;
   public:
      Queue(int a=5);
      ~Queue();
      //append to last item and removes first item
      void shift(float a);
      //two versions of overloaded indexing operators
      float & operator[](int i);
      const float & operator[](int i) const ;
      //assignment operator
      Queue operator=(const Queue & q);
      //queue io
      friend std::ostream & operator<<(std::ostream & os, const Queue & q1);
};

#endif
