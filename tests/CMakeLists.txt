cmake_minimum_required (VERSION 3.8)

set(This Tests)

set(Sources 
	Tuple_test.cpp
	Color_test.cpp
	Canvas_test.cpp
	Matrix_test.cpp
	Transformations_test.cpp
	Ray_test.cpp
	Sphere_test.cpp
	Intersection_test.cpp
	Object_test.cpp
	Light_test.cpp
	Material_test.cpp
	World_test.cpp
	Computation_test.cpp
	Camera_test.cpp
	Plane_test.cpp
	Pattern_test.cpp
	Stripe_test.cpp
	Gradient_test.cpp
	Ring_test.cpp
	Grid_test.cpp
	Solid_test.cpp
	../src/Tuple/Tuple.cpp
	../src/Color/Color.cpp
	../src/Canvas/Canvas.cpp
	../src/Matrix/Matrix.cpp
	../src/Transformations/Transformations.cpp
	../src/Ray/Ray.cpp
	../src/Intersection/Intersection.cpp
	../src/Light/Light.cpp
	../src/Material/Material.cpp
	../src/World/World.cpp
	../src/Computation/Computation.cpp
	../src/Camera/Camera.cpp
	../src/Object/Object.cpp
	../src/Object/Sphere/Sphere.cpp
	../src/Object/Plane/Plane.cpp
	../src/Pattern/Pattern.cpp
	../src/Pattern/Stripe/Stripe.cpp
	../src/Pattern/Gradient/Gradient.cpp
	../src/Pattern/Ring/Ring.cpp
	../src/Pattern/Grid/Grid.cpp
	../src/Pattern/Solid/Solid.cpp
	)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
)

target_include_directories(${This} PUBLIC
	../src/Tuple
	../src/Color
	../src/Canvas
	../src/Matrix
	../src/Transformations
	../src/Ray
	../src/Object/Sphere
	../src/Intersection
	../src/Object
	../src/Light
	../src/Material
	../src/World
	../src/Computation
	../src/Camera
	../src/Object/Plane
	../src/Pattern
	../src/Pattern/Stripe
	../src/Pattern/Gradient
	../src/Pattern/Ring
	../src/Pattern/Grid
	../src/Pattern/Solid
)

add_test(
	NAME ${This}
	COMMAND ${This}
)