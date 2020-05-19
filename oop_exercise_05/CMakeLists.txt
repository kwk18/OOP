cmake_minimum_required(VERSION 3.2)

project(lab5)

add_executable(run
		main.cpp
		rectangle.h
		vector.h
		vertex.h
		DynamicArray.h
	)

set_property(TARGET run PROPERTY CXX_STANDARD 17)
