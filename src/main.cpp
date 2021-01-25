#include <iostream>
#include <limits>

#include "Canvas.h"
#include "Sphere.h"
#include "Ray.h"

int main()
{
	//define canvas and its distance to the camera
	int pixels = 800;
	Canvas canvas(pixels, pixels);

	Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
	float wallZ = 10.0f;

	float wallSize = 7.0f;
	float pixelSize = wallSize / pixels;

	float half = wallSize / 2;
		
	//define sphere in the scene
	Sphere sphere;
	Color pink(1.0f, 0.2f, 0.8f);
	sphere.material.color = pink;

	//define light source
	Tuple lightPosition = Tuple::Point(-10.0f, 10.0f, -10.0f);
	Color lightColor(0.5f, 0.2f, 1.0f);
	Light light(lightPosition, lightColor);

	//compute color for each pixel
	for(int y = 0; y < pixels; y++) {
		float worldY = half - (pixelSize*y);

		for(int x = 0; x < pixels; x++) {
			float worldX = half - (pixelSize*x);
			
			Tuple pos = Tuple::Point(worldX, worldY, wallZ);
			Ray ray(rayOrigin, normalize(pos - rayOrigin));

			Intersection* intersection = intersects(ray, sphere);
			std::vector<Intersection> intersections = {intersection[0], intersection[1]};

			Intersection currentHit = hit(intersections);
			if (currentHit.t != std::numeric_limits<float>::infinity()) {
				Tuple point = position(ray, currentHit.t);
				Tuple normal = currentHit.surface->normal(point);
				Tuple eyeDirection = -ray.direction;
				Color finalColor = lighting(currentHit.surface->material, light, point, eyeDirection, normal);
				canvas.writePixel(x, y, finalColor);
			}
		}
	}

	writeFile(canvas, "test");
	return 0;
}
