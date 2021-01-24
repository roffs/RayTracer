#include <iostream>
#include <limits>

#include "Canvas.h"
#include "Sphere.h"
#include "Ray.h"

int main()
{

	int pixels = 800;
	Canvas canvas(pixels, pixels);
	Color red(1.0f, 0.0f, 0.0f);

	Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
	float wallZ = 10.0f;
	
	Sphere sphere;

	float wallSize = 7.0f;
	float pixelSize = wallSize / pixels;

	float half = wallSize / 2;

	for(int y = 0; y < pixels; y++) {
		float worldY = half - (pixelSize*y);

		for(int x = 0; x < pixels; x++) {
			float worldX = half - (pixelSize*x);
			
			Tuple position = Tuple::Point(worldX, worldY, wallZ);
			Ray ray(rayOrigin, normalize(position - rayOrigin));

			Intersection* intersection = intersects(ray, sphere);
			std::vector<Intersection> intersections = {intersection[0], intersection[1]};

			if (hit(intersections).t != std::numeric_limits<float>::infinity()) {
				canvas.writePixel(x, y, red);
			}
		}
	}

	writeFile(canvas, "test");
	return 0;
}
