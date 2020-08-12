#include "matrix.h"
#include <iostream>
#include "time.h"

Matrix::Matrix(int x, int y, int initialize){
   xdims = x;
   ydims = y;
   pt = new float[xdims * ydims];
   if(initialize){
      for(int i = 0; i < xdims * ydims; i++){
         pt[i] = float(rand()) / RAND_MAX;
      }
   }else {
      for(int i = 0; i < xdims * ydims; i++){
         pt[i] = 0;
      }
   }
}

Matrix::Matrix(){
   pt = NULL;
}

Matrix::Matrix(const Matrix & m1){
   xdims = m1.xdims;
   ydims = m1.ydims;
   pt = new float[xdims * ydims];
   for(int i = 0; i < xdims * ydims; i++){
      pt[i] = m1.pt[i];
   }
}

Matrix::~Matrix(){
   delete [] pt;
}

//operators & arithmetic

//assignment operator
Matrix & Matrix::operator=(const Matrix & m1){
   if(pt == m1.pt){
      return *this;
   }
   delete [] pt;
   xdims = m1.xdims;
   ydims = m1.ydims;
   pt = new float[xdims * ydims];
   for(int i = 0; i < xdims * ydims; i++){
      pt[i] = m1.pt[i];
   }
   return *this;
}

//element wise addition
Matrix Matrix::operator+(const Matrix & m2) const{
   if(!(xdims == m2.xdims && ydims == m2.ydims)){
      Matrix m3;
      return m3;
   }
   
   Matrix m3(xdims, ydims, 0);
   for(int i = 0; i < xdims * ydims; i++){
      m3.pt[i] = pt[i] + m2.pt[i];
   }
   return m3;
}

//element wise subtraction
Matrix Matrix::operator-(const Matrix & m2) const{
   if(!(xdims == m2.xdims && ydims == m2.ydims)){
      Matrix m3;
      return m3;
   }
   
   Matrix m3(xdims, ydims, 0);
   for(int i = 0; i < xdims * ydims; i++){
      m3.pt[i] = pt[i] - m2.pt[i];
   }
   return m3;
}

//scalar product
Matrix Matrix::operator*(const float b) const{
   Matrix m3(xdims, ydims, 0);
   for(int i = 0; i < xdims * ydims; i++){
      m3.pt[i] = pt[i] * b;
   }
   return m3;
}

//scalar product friend function
Matrix operator*(const float b, const Matrix & m1){
   Matrix m3(m1.xdims, m1.ydims, 0);
   for(int i = 0; i < m1.xdims * m1.ydims; i++){
      m3.pt[i] = m1.pt[i] * b;
   }
   return m3;
}

// matrix product
Matrix Matrix::operator*(const Matrix & m2) const{
   if(ydims != m2.xdims){
      std::cout << "ERROR SHAPE MISMATCH" << std::endl;
      Matrix m3;
      return m3;
   }
   int n = ydims;
   Matrix m3(xdims, m2.ydims, 0);
   float temp;
   for(int i = 0; i < m3.xdims; i++){
      for(int j = 0; j < m3.ydims; j++){
         temp = 0;
         //dot product
         for(int k = 0; k < n; k++){
            temp += (pt[i * xdims + k] * m2.pt[k * m2.ydims + j]);
         }
         m3.pt[i * m3.xdims + j * m3.ydims] = temp;
      }
   }
   return m3;
}

//concatenate matrices
Matrix Matrix::concat(const Matrix & B) const{
   Matrix m3;
   return m3;
}

int Matrix::operator==(const Matrix & m2) const{
   if(xdims != m2.xdims || ydims != m2.ydims){
      return 0;
   }
   for(int i = 0; i < xdims * ydims; i++){
      if(pt[i] != m2.pt[i]){
         return 0;
      }
   }
   return 1;
}

//indexing and selecting
//float & Matrix::operator[](int i){
//  return pt[i];
//}


//matrix io for debug
std::ostream & operator<< (std::ostream & os, const Matrix & m1){
   int k;
   if(!(m1.pt)){
      os << "ERROR: NULL MATRIX";
   }
   for(int i = 0; i < m1.xdims; i++){
      for(int j = 0; j < m1.ydims; j++){
         k = i * m1.xdims + j * m1.ydims;
         os << m1.pt[k] << " ";
      }
      os << std::endl;
   }
   return os;
}
