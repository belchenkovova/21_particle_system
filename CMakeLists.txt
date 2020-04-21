cmake_minimum_required(VERSION 3.15)
project(particle_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Winline")

include_directories(
	project)

include_directories(
	/usr/local/include
	/opt/local/include)

link_directories(
	/usr/local/lib
	/opt/local/lib)

link_libraries(
	"-framework OpenGL"
	"-framework OpenCL"
	GLFW
	GLEW
	SOIL)

set(MAIN
	project/main.cpp)

set(COMMON
	project/common/exception.cpp
	project/common/read_file.cpp)

set(ENGINE
	project/engine/core/core.cpp
	project/engine/core/calculate_fps.cpp
	project/engine/core/draw.cpp
	project/engine/core/finish.cpp
	project/engine/core/start.cpp
	project/engine/core/glfw_callback_x.cpp
	project/engine/core/launch_x.cpp
	project/engine/core/receive_event.cpp

	project/engine/shader/shader.cpp
	project/engine/uniform/uniform.cpp
	project/engine/program/program.cpp

	project/engine/vao/vao.cpp
	project/engine/buffer/buffer.cpp

	project/engine/camera/camera.cpp

	project/engine/event/event.cpp
	)

set(COMPUTER
	project/computer/core/core.cpp
	project/computer/kernel/kernel.cpp
	project/computer/argument/argument.cpp)

set(PARTICLE_SYSTEM
	project/particle_system/map/map.cpp

	project/particle_system/manager/renderer.cpp

	project/particle_system/manager/build.cpp
	project/particle_system/manager/function_x.cpp
	project/particle_system/manager/engine_x.cpp
	project/particle_system/manager/computer_x.cpp
	project/particle_system/manager/initialize.cpp)

add_executable(particle_system
	${MAIN}
	${COMMON}
	${ENGINE}
	${COMPUTER}
	${PARTICLE_SYSTEM})