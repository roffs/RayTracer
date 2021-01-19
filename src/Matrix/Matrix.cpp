#include "Matrix.h"
#include <iostream>

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

Matrix::Matrix(int dimension) : array{new float[dimension*dimension]}, dimension{dimension} {};

//Operator overloads

float& Matrix::operator() (int x, int y)
{
  return array[x*dimension + y];
};

float& Matrix::operator() (int x, int y) const
{
  return array[x*dimension + y];
};

bool Matrix::operator== (Matrix const& other) {
  if (dimension != other.dimension) { return false; }
  
  for(int i = 0; i < (dimension*dimension)-1; i++) {
    if(array[i] - other.array[i] > 0.0001) { return false; }
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
      result[row*dimension + col] = ((*this)(row, 0) * other(0, col)) +
                                    ((*this)(row, 1) * other(1, col)) +
                                    ((*this)(row, 2) * other(2, col)) +
                                    ((*this)(row, 3) * other(3, col));
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
      result[row] = ((*this)(row, 0) * tuple.x) +
                    ((*this)(row, 1) * tuple.y) +
                    ((*this)(row, 2) * tuple.z) +
                    ((*this)(row, 3) * tuple.w);
  };

  return {result[0], result[1], result[2], result[3]};
};

 Matrix Matrix::operator* (float const& scalar) {
   Matrix result(dimension);
   for (int i = 0; i < dimension; i++){
     for (int j = 0; j < dimension; j++){
       result(i, j) = (*this)(i, j) * scalar;
     }
   }
   return result;
 };


//Out of scope of class

Matrix transpose(Matrix const& matrix){
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

float determinant(Matrix const& matrix){
  float det = 0;
  if (matrix.dimension == 2) {
    det = matrix.array[0]*matrix.array[3] - matrix.array[1]*matrix.array[2];    
  }
  else {
    for (int i = 0; i < matrix.dimension; i++) {
      det += matrix(0, i)*cofactor(matrix, 0, i);
    }
  }
  return det;    
};

Matrix subMatrix(Matrix const& matrix, int row, int col) {
  Matrix sub{matrix.dimension-1};

  int i_col = 0, i_row = 0;
  int i = 0;

  while(i < (matrix.dimension-1)*(matrix.dimension-1)) {

    if (col != i_col && row != i_row) {
       sub.array[i] = matrix(i_row, i_col);
      i++;
    }

    if (!(i_col < (matrix.dimension-1))) {
      i_col = 0;
      i_row++;
    } else {
      i_col++;
    }
  }

  return sub;
};

float minor(Matrix const& matrix, int row, int column) {
  return determinant(subMatrix(matrix, row, column));
};

float cofactor(Matrix const& matrix, int row, int column) {
  float min = minor(matrix, row, column);
  int sign = (row+column) % 2 == 0 ? 1 : -1;
  return sign*min;
};

bool isInvertible(Matrix const& matrix) {
  return determinant(matrix) != 0;
};

Matrix inverse(Matrix const& matrix) {
  Matrix inv = Matrix(matrix.dimension);
  float det = determinant(matrix);

  for (int i = 0; i < matrix.dimension; i++){
    for (int j = 0; j < matrix.dimension; j++){
      inv(j, i) = cofactor(matrix, i, j) / det;
    }
  }

  return inv;
};