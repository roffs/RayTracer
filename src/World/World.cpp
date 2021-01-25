#include "World.h"
#include "Sphere.h"
#include "Transformations.h"

World::World() {};


World defaultWorld() {
    //set light
    Tuple lightPosition = Tuple::Point(-10.0f, 10.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light* light = new Light(lightPosition, lightColor);

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
    world.lights.push_back(light);

    return world;
};