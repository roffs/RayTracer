cmake_minimum_required (VERSION 3.8)

set(This Tests)

set(Sources 
	Tuple_test.cpp
	../src/Tuple/Tuple.h
	../src/Tuple/Tuple.cpp
	)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
)

target_include_directories(${This} PUBLIC
	../src/Tuple
)

add_test(
	NAME ${This}
	COMMAND ${This}
)