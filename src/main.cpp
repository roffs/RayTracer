#include <iostream>
#include <limits>

#define _USE_MATH_DEFINES
#include <cmath>

#include "Canvas.h"
#include "Sphere.h"
#include "Plane.h"
#include "Ray.h"
#include "Transformations.h"
#include "World.h"
#include "Light.h"
#include "Camera.h"

#include "Pattern.h"
#include "Grid.h"
#include "Stripe.h"
#include "Gradient.h"
#include "Solid.h"

int main()
{
	//Floor
	Plane floor;
	Grid grid = Grid(Color(1.0f, 1.0f, 1.0f), Color(0.0f, 0.0f, 0.0f));
	floor.material.setPattern(grid);
	floor.material.diffuse = 0.7f;
	floor.material.specular = 0.3f;
	
	//Sphere1
	Sphere middle;
	middle.setTransformation(translation(-0.5f, 1.0f, 0.5f));
	middle.material = Material();

	Grid grid3 = Grid(Color(0.8f, 0.1f, 0.9f), Color(0.1f, 0.7f, 0.5f));
	Solid solid = Solid(Color(1.0f, 1.0f, 1.0f));
	middle.material.color = Color(0.7f, 0.8f, 0.8f);
	middle.material.diffuse = 0.7f;
	middle.material.specular = 0.3f;
	middle.material.reflective = 0.8f;

	//Sphere2
	Sphere right;
	right.setTransformation(translation(1.5f, 0.5f, -0.5f) * scaling(0.5f, 0.5f, 0.5f));
	right.material = Material();
	right.material.color = Color(0.5f, 1.0f, 0.1f);
	right.material.diffuse = 0.7f;
	right.material.specular = 0.3f;
	right.material.reflective = 0.5f;
	
	//Sphere3
	Sphere left;
	left.setTransformation(translation(-1.5f, 0.33f, -0.75f) * scaling(0.33f, 0.33f, 0.33f));
	left.material = Material();
	Gradient gradient = Gradient(Color(1.0f, 1.0f, 0.85f), Color(0.8f, 0.15f, 0.55f));
	gradient.transform = rotation_z(M_PI/8)*scaling(2.25f, 2.25f, 2.25f)*translation(-0.5f, 0.0f, 0.0f);
	left.material.setPattern(gradient);
	left.material.color = Color(1.0f, 0.8f, 0.1f);
	left.material.diffuse = 0.7f;
	left.material.specular = 0.3f;
	left.material.reflective = 0.5f;

	World world;
	world.objects = {&floor, &middle, &right, &left};
	world.light = Light(Tuple::Point(-10.0f, 10.0f, -10.0f), Color(1.0f, 1.0f, 1.0f));

	Camera camera(1024, 720, M_PI/3.0f);
	camera.transform = viewTransformation(Tuple::Point(0.0f, 1.5f, -5.0f), Tuple::Point(0.0f, 1.0f, 0.0f), Tuple::Vector(0.0f, 1.0f, 0.0f));

	Canvas canvas = render(camera, world);
	writeFile(canvas, "test");
	
	return 0;
}
