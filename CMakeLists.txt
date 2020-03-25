cmake_minimum_required(VERSION 3.15)
project(21_particle_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

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

set(MAIN
	project/main.cpp)

set(COMMON
	project/common/exception.cpp
	project/common/read_file.cpp)

set(ENGINE
	project/engine/core/core.cpp
	project/engine/program/shader.cpp
	project/engine/program/program.cpp
	project/engine/buffer/vao.cpp
	project/engine/buffer/buffer.cpp
	project/engine/camera/camera.cpp
	project/engine/renderer/renderer.cpp)

set(COMPUTER
	project/computer/core/core.cpp
	project/computer/kernel/kernel.cpp
	project/computer/buffer/buffer.cpp)

add_executable(21_particle_system
	${MAIN}
	${COMMON}
	${ENGINE}
	${COMPUTER})