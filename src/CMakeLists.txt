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
	Object/Object.cpp
	Light/Light.cpp
	Material/Material.cpp
	World/World.cpp
	Computation/Computation.cpp
	Camera/Camera.cpp
	Plane/Plane.cpp
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
	Object
	Light
	Material
	World
	Computation
	Camera
	Plane
)