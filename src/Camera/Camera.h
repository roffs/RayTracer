#pragma once

#include "Matrix.h"
#include "Ray.h"
#include "Canvas.h"
#include "World.h"

class Camera {
public:
    int hsize;
    int vsize;
    float fieldOfView;
    float halfWidth;
    float halfHeight;
    float pixelSize;
    Matrix transform;

    Camera(int hsize, int vsize, float fieldOfView);

    Ray rayForPixel(int x, int y) const;

private:
    void calculateSizes();
};

Canvas render(Camera const &camera, World const &world);