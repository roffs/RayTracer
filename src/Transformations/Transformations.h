#pragma once

#include "Matrix.h"

Matrix translation(float x, float y, float z);

Matrix scaling(float x, float y, float z);

Matrix rotation_x(float rad);
Matrix rotation_y(float rad);
Matrix rotation_z(float rad);

Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);

Matrix viewTransformation(Tuple const &from, Tuple const &to, Tuple const &up);