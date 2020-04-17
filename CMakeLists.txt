cmake_minimum_required(VERSION 3.15)
project(21_particle_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Winline")

include_directories(
	project)

include_directories(
	/usr/local/include
	/opt/local/include
	/usr/local/include/freetype2)

link_directories(
	/usr/local/lib
	/opt/local/lib)

link_libraries(
	"-framework OpenGL"
	"-framework OpenCL"
	GLFW
	GLEW
	Freetype
	SOIL)

set(MAIN
	project/main.cpp)

set(COMMON
	project/common/exception.cpp
	project/common/read_file.cpp)

set(ENGINE
	project/engine/core/core.cpp
	project/engine/point/point.cpp
	project/engine/core/settings.cpp
	project/engine/core/launch_x.cpp
	project/engine/core/glfw_callback_x.cpp
	project/engine/shader/shader.cpp
	project/engine/uniform/uniform.cpp
	project/engine/program/program.cpp
	project/engine/ebo/ebo.cpp
	project/engine/vao/vao.cpp
	project/engine/buffer/buffer.cpp
	project/engine/camera/camera.cpp
	project/engine/functor/functor.cpp
	project/engine/timer/timer.cpp
	project/engine/event/event.cpp
	project/engine/callback/callback.cpp
	project/engine/texture/texture.cpp)

set(COMPUTER
	project/computer/core/core.cpp
	project/computer/kernel/kernel.cpp
	project/computer/argument/argument.cpp)

set(PARTICLE_SYSTEM
	project/particle_system/particle_system.cpp
	project/particle_system/renderer.cpp)

add_executable(21_particle_system
	${MAIN}
	${COMMON}
	${ENGINE}
	${COMPUTER}
	${PARTICLE_SYSTEM})