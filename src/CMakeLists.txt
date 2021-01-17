cmake_minimum_required (VERSION 3.8)

set(This RayTracer)

set(Sources 
	main.cpp
	Tuple/Tuple.h
	Tuple/Tuple.cpp
	)

add_executable(${This} ${Sources})

target_include_directories(${This} PUBLIC
	Tuple
)