cmake_minimum_required(VERSION 3.15)
project(21_particle_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Winline")

include_directories(
	project)

include_directories(
	/usr/local/Cellar/glew/2.1.0_1/include
	/usr/local/Cellar/glfw/3.3/include
	/usr/local/Cellar/glm/0.9.9.5/include
	/usr/local/Cellar/freetype/2.10.1/include/freetype2)

link_directories(
	/usr/local/Cellar/glew/2.1.0_1/lib
	/usr/local/Cellar/glfw/3.3/lib
	/usr/local/Cellar/freetype/2.10.1/lib)

link_libraries(
	"-framework OpenGL"
	"-framework OpenCL"
	GLFW
	GLEW
	Freetype)

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

set(GUI
	project/gui/symbol/symbol.cpp
	project/gui/font/font.cpp
	project/gui/renderers/renderers.cpp
	project/gui/label/label.cpp
	project/gui/button/button.cpp
	project/gui/button/button_with_label.cpp
	project/gui/container/horizontal_pack.cpp
	project/gui/container/button_pack.cpp
	project/gui/system/system.cpp
	project/gui/system/renderer.cpp)

set(PARTICLE_SYSTEM
	project/particle_system/particle_system.cpp
	project/particle_system/renderers.cpp)

add_executable(21_particle_system
	${MAIN}
	${COMMON}
	${ENGINE}
	${COMPUTER}
	${GUI}
	${PARTICLE_SYSTEM})