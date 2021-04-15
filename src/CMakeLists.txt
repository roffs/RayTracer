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
	Intersection/Intersection.cpp
	Light/Light.cpp
	Material/Material.cpp
	World/World.cpp
	Computation/Computation.cpp
	Camera/Camera.cpp
	Object/Object.cpp
	Object/Plane/Plane.cpp
	Object/Sphere/Sphere.cpp
	Object/Cube/Cube.cpp
	Pattern/Pattern.cpp
	Pattern/Stripe/Stripe.cpp
	Pattern/Gradient/Gradient.cpp
	Pattern/Ring/Ring.cpp
	Pattern/Grid/Grid.cpp
	Pattern/Solid/Solid.cpp
	)

add_executable(${This} ${Sources})

target_include_directories(${This} PUBLIC
	Tuple
	Color
	Canvas
	Matrix
	Transformations
	Ray
	Object/Sphere
	Object/Plane
	Object/Cube
	Intersection
	Object
	Light
	Material
	World
	Computation
	Camera
	Pattern
	Pattern/Stripe
	Pattern/Gradient
	Pattern/Ring
	Pattern/Grid
	Pattern/Solid
)