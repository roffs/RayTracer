#include <algorithm>
#include <limits>
#include <cmath>

#include "World.h"
#include "Sphere.h"
#include "Transformations.h"

World::World() {};


World World::DefaultWorld() {
    //set light
    Tuple lightPosition = Tuple::Point(-10.0f, 10.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light light(lightPosition, lightColor);

    //set sphere1 and its material
    Sphere* sphere1 = new Sphere();
    Color color1(0.8f, 1.0f, 0.6f);
    Material material1;
    material1.color = color1;
    material1.diffuse = 0.7f;
    material1.specular = 0.2f; 
    sphere1->material = material1;

    //set sphere2
    Sphere* sphere2 = new Sphere();
    sphere2->setTransformation(scaling(0.5f, 0.5f, 0.5f));

    World world;
    world.objects.push_back(sphere1); 
    world.objects.push_back(sphere2); 
    world.light = light;

    return world;
};

bool World::isShadow(Tuple point) const {
    Tuple pointToLight = light.position - point;
    float distance = magnitude(pointToLight);
    Tuple direction = normalize(pointToLight);

    Ray ray(point, direction);
    std::vector<Intersection> intersections = intersectsWorld(ray, *this);

    bool shadow = false; 

    if (intersections.size() > 0) {
        Intersection i = hit(intersections);

        if (i.t < distance) {
            shadow = true;
        }
    }

    return shadow; 
};

//out of class

std::vector<Intersection> intersectsWorld(Ray const &ray, World const &world) {
    std::vector<Intersection> worldIntersections;    
    
    for (auto object : world.objects) {
        std::vector<Intersection> objectIntersections = object->intersects(ray);
        worldIntersections.insert(std::end(worldIntersections), std::begin(objectIntersections), std::end(objectIntersections));
    };

    //sort by t
    std::sort(worldIntersections.begin(), worldIntersections.end(), [](const Intersection& lhs, const Intersection& rhs) { 
        return lhs.t < rhs.t; 
    });

    return worldIntersections;
};

Color shadeHit(World const &world, Computation const &comp, int remaining) {
    bool isShadowed = world.isShadow(comp.overPoint);
    Color surface = lighting(comp.object, world.light, comp.overPoint, comp.eyeDirection, comp.normal, isShadowed); //TODO: support multiple light sources
    Color reflected = reflectedColor(world, comp, remaining);
    Color refracted = refractedColor(world, comp, remaining);
    return surface + reflected + refracted;
};

Color colorAt(World const &world, Ray const &ray, int remaining) {
    Color color(0.0f, 0.0f, 0.0f);

    std::vector<Intersection> intersections = intersectsWorld(ray, world);

    if (intersections.size() > 0){
        Intersection intersection = hit(intersections);
        if (intersection.t < std::numeric_limits<float>::infinity()) {
            Computation comp = prepareComputation(intersection, ray, intersections);
            color = shadeHit(world, comp, remaining);
        }
    }
    return color;
};


Color reflectedColor(World const &world, Computation const &comp, int remaining) {
    float reflective = comp.object->material.reflective;
    if (reflective == 0.0f || remaining < 1) {
        return {0.0f, 0.0f, 0.0f};
    }
    else {
        Ray reflectedRay(comp.overPoint, comp.reflectv);
        Color color = colorAt(world, reflectedRay, remaining - 1);
        return color * reflective;
    }
};


Color refractedColor(World const &world, Computation const &comp, int remaining) {
    if (comp.object->material.transparency == 0.0f || remaining == 0) {
        return {0.0f, 0.0f, 0.0f};
    } 
    
    float nRatio = comp.n1 / comp.n2;
    float cos_i = comp.eyeDirection * comp.normal;
    float sin2_t = (nRatio * nRatio) * (1 - (cos_i * cos_i));
    
    if (sin2_t > 1) {
        return {0.0f, 0.0f, 0.0f};
    }

    float cos_t = sqrt(1.0f - sin2_t);
    Tuple refractedDirection = comp.normal*(nRatio*cos_i - cos_t) - comp.eyeDirection*nRatio;

    Ray refractedRay(comp.underPoint, refractedDirection);

    Color color1 = colorAt(world, refractedRay, remaining-1);
    
    return colorAt(world, refractedRay, remaining-1) * comp.object->material.transparency;
};
