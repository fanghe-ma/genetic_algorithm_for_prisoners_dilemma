#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include "queue.h"

class Matrix{
   private:
      float * pt;
      int xdims;
      int ydims;

      friend class Player;
   public:
      //constructors and destructors
      Matrix(int x, int y, int initialize = 1);
      Matrix(const Matrix & m1);
      Matrix(const float * p, int x, int y);
      Matrix(const Queue & q);
      Matrix();
      ~Matrix();
      //typecast to bool
      operator bool() const{
         return(pt ? true : false);
      }
      //operators & arithmetic
      Matrix operator+(const Matrix & m2) const; //element wise addition
      Matrix operator-(const Matrix & m2) const; //element wise subtraction
      Matrix operator*(const float b) const; //scalar product
      friend Matrix operator*(const float b, const Matrix & m1); //scalar product
      Matrix operator*(const Matrix & m2) const; // matrix product

      Matrix concat(const Matrix & m2) const; //concatenate matrices
      int operator==(const Matrix & m2) const;  // comparison 
      Matrix & operator=(const Matrix & m1); //assignment operator
      Matrix join(const Matrix & m2) const; //joins matrices

      //matrix io 
      friend std::ostream & operator << (std::ostream & os, const Matrix & m1);

};


#endif
