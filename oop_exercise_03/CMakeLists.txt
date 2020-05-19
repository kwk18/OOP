project(lab3)

add_executable(lab3
	main.cpp
	Figures.cpp
	Figures.hpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")