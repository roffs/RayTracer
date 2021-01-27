#include <algorithm>
#include <limits>

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

Color shadeHit(World const &world, Computation const &comp) {
    return lighting(comp.object->material, world.light, comp.point, comp.eyeDirection, comp.normal); //TODO: support multiple light sources
};

Color colorAt(World const &world, Ray const &ray) {
    Color color(0.0f, 0.0f, 0.0f);

    std::vector<Intersection> intersections = intersectsWorld(ray, world);

    if (intersections.size() > 0){
        Intersection intersection = hit(intersections);
        if (intersection.t < std::numeric_limits<float>::infinity()) {
            Computation comp = prepareComputation(intersection, ray);
            color = shadeHit(world, comp);
        }
    }
    return color;
};
