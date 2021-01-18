#include "Matrix.h"

Matrix::Matrix(
  float x1, float x2, float x3, float x4,
  float y1, float y2, float y3, float y4, 
  float z1, float z2, float z3, float z4,
  float w1, float w2, float w3, float w4
  ) : array{new float[16]}, dimension(4) {
  array[0] = x1;
  array[1] = x2;
  array[2] = x3;
  array[3] = x4;

  array[4] = y1;
  array[5] = y2;
  array[6] = y3;
  array[7] = y4;
  
  array[8] = z1;
  array[9] = z2;
  array[10] = z3;
  array[11] = z4;

  array[12] = w1;
  array[13] = w2;
  array[14] = w3;
  array[15] = w4;
};

Matrix::Matrix(
  float x1, float x2, float x3,
  float y1, float y2, float y3, 
  float z1, float z2, float z3
  ) : array{new float[9]}, dimension(3) {
  array[0] = x1;
  array[1] = x2;
  array[2] = x3;

  array[3] = y1;
  array[4] = y2;
  array[5] = y3;
  
  array[6] = z1;
  array[7] = z2;
  array[8] = z3;
};

Matrix::Matrix(
  float x1, float x2, 
  float y1, float y2
  ) : array{new float[4]}, dimension(2) {
  array[0] = x1;
  array[1] = x2;

  array[2] = y1;
  array[3] = y2;
};


//Operator overloads

float& Matrix::operator() (int x, int y)
{
  return array[(x-1)*dimension + (y-1)];
};

float Matrix::operator() (int x, int y) const
{
  return array[(x-1)*dimension + (y-1)];
};

bool Matrix::operator== (Matrix const& other) {
  if (dimension != other.dimension) { return false; }
  
  for(int i = 0; i < (dimension*dimension)-1; i++) {
    if(array[i] != other.array[i]) { return false; }
  }

  return true;
};

bool Matrix::operator!= (Matrix const& other) {
  return !(*this == other);
};

Matrix Matrix::operator* (Matrix const& other) {
  float result[16];

  for(int row = 0; row < dimension; row++){
    for(int col = 0; col < dimension; col++){
      result[row*dimension + col] = ((*this).array[row*dimension + 0] * other.array[0*dimension + col]) +
                                    ((*this).array[row*dimension + 1] * other.array[1*dimension + col]) +
                                    ((*this).array[row*dimension + 2] * other.array[2*dimension + col]) +
                                    ((*this).array[row*dimension + 3] * other.array[3*dimension + col]);
    };
  };

  return  { 
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15],
          };
};

Tuple Matrix::operator* (Tuple const& tuple){
  float result[4];

  for(int row = 0; row < dimension; row++){
      result[row] = ((*this).array[row*dimension + 0] * tuple.x) +
                                    ((*this).array[row*dimension + 1] * tuple.y) +
                                    ((*this).array[row*dimension + 2] * tuple.z) +
                                    ((*this).array[row*dimension + 3] * tuple.w);
  };

  return {result[0], result[1], result[2], result[3]};
};


//Out of scope of class

Matrix transpose(Matrix matrix){
  float result[16];

  for(int row = 0; row < 4; row++){
    for(int col = 0; col < 4; col++){
      result[row*4 + col] = matrix.array[col*4 + row];
    };
  };

  
  return  { 
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15],
          };
};