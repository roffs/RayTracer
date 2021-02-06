#include <cmath>

#include "Camera.h"

#define MAX_BOUNCES 3

Camera::Camera(int hsize, int vsize, float fieldOfView) : 
    hsize(hsize), vsize(vsize), fieldOfView(fieldOfView), transform(Matrix::Identity(4)) {
        calculateSizes();
    };

void Camera::calculateSizes() {
    float halfView = tan(fieldOfView/2.0f);
    float aspect = (float)hsize / vsize;

    if (aspect < 1) {
        halfWidth = halfView * aspect;
        halfHeight = halfView;
    }
    else{
        halfWidth = halfView;
        halfHeight = halfView / aspect;
    }
    pixelSize = (halfWidth*2.0f)/hsize;
};

Ray Camera::rayForPixel(int x, int y) const {
    float xOffset = (x + 0.5f) * pixelSize;
    float yOffset = (y + 0.5f) * pixelSize;

    float worldX = halfWidth - xOffset;
    float worldY = halfHeight - yOffset;

    Matrix invTransform = inverse(transform);
    Tuple rayOrigin = invTransform * Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple pixel = invTransform * Tuple::Point(worldX, worldY, -1);
    Tuple rayDirection = normalize(pixel - rayOrigin);
    
    return {rayOrigin, rayDirection};
};

Canvas render(Camera const &camera, World const &world) {
	Canvas canvas(camera.hsize, camera.vsize);

	//compute color for each pixel
	for(int y = 0; y < camera.vsize; y++) {
		for(int x = 0; x < camera.hsize; x++) {
			Ray ray = camera.rayForPixel(x, y);
            Color color = colorAt(world, ray, MAX_BOUNCES);
            canvas.writePixel(x, y, color);
        }
	}
    return canvas; 
};