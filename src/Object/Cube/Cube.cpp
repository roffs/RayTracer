#include "Cube.h"

#include <vector>
#include <limits>
#include <algorithm>

#include "Intersection.h"
#include "Ray.h"


std::vector<Intersection> Cube::localIntersects(Ray const &ray) {
    float* x = check_axis(ray.origin.x, ray.direction.x);
    float* y = check_axis(ray.origin.y, ray.direction.y);
    float* z = check_axis(ray.origin.z, ray.direction.z);

    float tmin = std::max({x[0], y[0], z[0]}); //TODO: book says it should be max? 
    float tmax = std::min({x[1], y[1], z[1]});

    std::vector<Intersection> intersections;

    if (tmin<tmax){
        Intersection int1(*this, tmin);
        intersections.push_back(int1);

        Intersection int2(*this, tmax);
        intersections.push_back(int2);
    }
        
    return intersections;
}

Tuple Cube::localNormalAt(Tuple const &localPoint) {
    if (localPoint.x == 1.0f || localPoint.x == -1.0f) {
        return Tuple::Vector(localPoint.x, 0.0f, 0.0f);
    }
    if (localPoint.y == 1.0f || localPoint.y == -1.0f) {
        return Tuple::Vector(0.0f, localPoint.y, 0.0f);
    }
    return Tuple::Vector(0.0f, 0.0f, localPoint.z);
}


float* check_axis(float origin, float direction) {
    float tmin_num = (-1 - origin);
    float tmax_num = 1 - origin;

    float tmin, tmax; 

    float absDir = direction;
    if(absDir < 0) {
        absDir *= -1;
    }
    if (absDir > EPSILON) {
        tmin = tmin_num / direction;
        tmax = tmax_num / direction;    
    } 
    else {
        tmin = tmin_num * std::numeric_limits<float>::infinity();
        tmax = tmax_num * std::numeric_limits<float>::infinity();
    }

    if (tmin > tmax) {
        float tmp = tmin;
        tmin = tmax; 
        tmax = tmp;
    }

    float* result = new float[2];
    result[0] = tmin;
    result[1] = tmax;

    return result;
}