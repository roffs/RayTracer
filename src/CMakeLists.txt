cmake_minimum_required (VERSION 3.8)

set(This RayTracer)

set(Sources 
	main.cpp
	Tuple/Tuple.cpp
	Color/Color.cpp
	Canvas/Canvas.cpp
	Matrix/Matrix.cpp
	Transformations/Transformations.cpp
	Ray/Ray.cpp
	Sphere/Sphere.cpp
	Intersection/Intersection.cpp
	Surface/Surface.cpp
	Light/Light.cpp
	)

add_executable(${This} ${Sources})

target_include_directories(${This} PUBLIC
	Tuple
	Color
	Canvas
	Matrix
	Transformations
	Ray
	Sphere
	Intersection
	Surface
	Light
)