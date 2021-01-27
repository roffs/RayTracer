#include "Transformations.h"

#include <cmath>

Matrix translation(float  x, float y, float z) {
    Matrix result = Matrix::Identity(4);
    result(0, 3) = x;
    result(1, 3) = y;
    result(2, 3) = z;
    return result;
};

Matrix scaling(float x, float y, float z) {
    Matrix result = Matrix::Identity(4);
    result(0, 0) = x;
    result(1, 1) = y;
    result(2, 2) = z;
    return result;
};

Matrix rotation_x(float rad) {
    Matrix result = Matrix::Identity(4);
    result(1, 1) = cos(rad);
    result(1, 2) = -sin(rad);
    result(2, 1) = sin(rad);
    result(2, 2) = cos(rad);
    return result;   
};

Matrix rotation_y(float rad) {
    Matrix result = Matrix::Identity(4);
    result(0, 0) = cos(rad);
    result(0, 2) = sin(rad);
    result(2, 0) = -sin(rad);
    result(2, 2) = cos(rad);
    return result;   
};

Matrix rotation_z(float rad) {
    Matrix result = Matrix::Identity(4);
    result(0, 0) = cos(rad);
    result(0, 1) = -sin(rad);
    result(1, 0) = sin(rad);
    result(1, 1) = cos(rad);
    return result;   
};

Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y){
    Matrix result = Matrix::Identity(4);
    result(0, 1) = x_y;
    result(0, 2) = x_z;
    result(1, 0) = y_x;
    result(1, 2) = y_z;
    result(2, 0) = z_x;
    result(2, 1) = z_y;
    return result;   
};

Matrix viewTransformation(Tuple const &from, Tuple const &to, Tuple const &up) {
    
    Tuple forward = normalize(to - from);
    Tuple left = cross(forward, normalize(up));

    Tuple trueUp = cross(left, forward);

    Matrix orientation (
        left.x, left.y, left.z, 0.0f,
        trueUp.x, trueUp.y, trueUp.z, 0.0f,
        -forward.x, -forward.y, -forward.z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    return orientation * translation(-from.x, -from.y, -from.z);
};