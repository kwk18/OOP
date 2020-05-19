project(lab1)

add_executable(lab1
	main.cpp
	BitString.h)


set(CMAKE_CXX_FLAGS
	"${CMAKE_CXX_FLAGS} -Wall -Wextra")
