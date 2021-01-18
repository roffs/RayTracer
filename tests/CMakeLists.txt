cmake_minimum_required (VERSION 3.8)

set(This Tests)

set(Sources 
	Tuple_test.cpp
	Color_test.cpp
	Canvas_test.cpp
	Matrix_test.cpp
	../src/Tuple/Tuple.cpp
	../src/Color/Color.cpp
	../src/Canvas/Canvas.cpp
	../src/Matrix/Matrix.cpp
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
)

add_test(
	NAME ${This}
	COMMAND ${This}
)