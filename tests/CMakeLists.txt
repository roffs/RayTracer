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
	../src/Tuple/Tuple.cpp
	../src/Color/Color.cpp
	../src/Canvas/Canvas.cpp
	../src/Matrix/Matrix.cpp
	../src/Transformations/Transformations.cpp
	../src/Ray/Ray.cpp
	../src/Sphere/Sphere.cpp
	../src/Intersection/Intersection.cpp
	../src/Object/Object.cpp
	../src/Light/Light.cpp
	../src/Material/Material.cpp
	../src/World/World.cpp
	../src/Computation/Computation.cpp
	../src/Camera/Camera.cpp
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
	../src/Sphere
	../src/Intersection
	../src/Object
	../src/Light
	../src/Material
	../src/World
	../src/Computation
	../src/Camera
)

add_test(
	NAME ${This}
	COMMAND ${This}
)