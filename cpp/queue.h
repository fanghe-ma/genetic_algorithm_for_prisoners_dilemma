#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>

class Queue{
   private:
      float * pt;
      int num_items;

      friend class Matrix;
   public:
      Queue(int a=5);
      ~Queue();
      void shift(float a);
      float & operator[](int i);
      const float & operator[](int i) const ;
      friend std::ostream & operator<<(std::ostream & os, const Queue & q1);
};

#endif
