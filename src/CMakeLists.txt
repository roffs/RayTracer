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
	Object/Sphere/Sphere.cpp
	Intersection/Intersection.cpp
	Object/Object.cpp
	Light/Light.cpp
	Material/Material.cpp
	World/World.cpp
	Computation/Computation.cpp
	Camera/Camera.cpp
	Object/Plane/Plane.cpp
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
	Intersection
	Object
	Light
	Material
	World
	Computation
	Camera
	Object/Plane
	Pattern
	Pattern/Stripe
	Pattern/Gradient
	Pattern/Ring
	Pattern/Grid
	Pattern/Solid
)