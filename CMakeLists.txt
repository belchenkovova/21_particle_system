cmake_minimum_required(VERSION 3.15)
project(21_particle_system)

set(CMAKE_CXX_STANDARD 17)

include_directories(
	project)

include_directories(
	/usr/local/Cellar/glew/2.1.0_1/include
	/usr/local/Cellar/glfw/3.3/include
	/usr/local/Cellar/glm/0.9.9.5/include)

link_directories(
	/usr/local/Cellar/glew/2.1.0_1/lib
	/usr/local/Cellar/glfw/3.3/lib)

link_libraries(
	"-framework OpenGL"
	"-framework OpenCL"
	GLFW
	GLEW)

add_executable(21_particle_system project/main.cpp)