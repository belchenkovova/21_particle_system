#						FUNCTIONS

define INFO
${info ${PREFIX} : $1}
endef

#						VARIABLES

COMMA = ,

OBJECT_FOLDER = .object
DEPEND_FOLDER = .depend

COMPILER = clang++
PREFIX = particle_system
EXECUTABLE = particle_system

INCLUDE = -I ../project/
OBJECT = ${OBJECT_FOLDER}/main.cpp.o ${OBJECT_FOLDER}/exception.cpp.o ${OBJECT_FOLDER}/read_file.cpp.o ${OBJECT_FOLDER}/core.cpp.o ${OBJECT_FOLDER}/calculate_fps.cpp.o ${OBJECT_FOLDER}/draw.cpp.o ${OBJECT_FOLDER}/finish.cpp.o ${OBJECT_FOLDER}/start.cpp.o ${OBJECT_FOLDER}/glfw_callback_x.cpp.o ${OBJECT_FOLDER}/launch_x.cpp.o ${OBJECT_FOLDER}/receive_event.cpp.o ${OBJECT_FOLDER}/shader.cpp.o ${OBJECT_FOLDER}/uniform.cpp.o ${OBJECT_FOLDER}/program.cpp.o ${OBJECT_FOLDER}/vao.cpp.o ${OBJECT_FOLDER}/buffer.cpp.o ${OBJECT_FOLDER}/camera.cpp.o ${OBJECT_FOLDER}/event.cpp.o ${OBJECT_FOLDER}/core_1.cpp.o ${OBJECT_FOLDER}/kernel.cpp.o ${OBJECT_FOLDER}/argument.cpp.o ${OBJECT_FOLDER}/map.cpp.o ${OBJECT_FOLDER}/renderer.cpp.o ${OBJECT_FOLDER}/build.cpp.o ${OBJECT_FOLDER}/function_x.cpp.o ${OBJECT_FOLDER}/engine_x.cpp.o ${OBJECT_FOLDER}/computer_x.cpp.o ${OBJECT_FOLDER}/initialize.cpp.o
DEPEND = ${DEPEND_FOLDER}/main.cpp.d ${DEPEND_FOLDER}/exception.cpp.d ${DEPEND_FOLDER}/read_file.cpp.d ${DEPEND_FOLDER}/core.cpp.d ${DEPEND_FOLDER}/calculate_fps.cpp.d ${DEPEND_FOLDER}/draw.cpp.d ${DEPEND_FOLDER}/finish.cpp.d ${DEPEND_FOLDER}/start.cpp.d ${DEPEND_FOLDER}/glfw_callback_x.cpp.d ${DEPEND_FOLDER}/launch_x.cpp.d ${DEPEND_FOLDER}/receive_event.cpp.d ${DEPEND_FOLDER}/shader.cpp.d ${DEPEND_FOLDER}/uniform.cpp.d ${DEPEND_FOLDER}/program.cpp.d ${DEPEND_FOLDER}/vao.cpp.d ${DEPEND_FOLDER}/buffer.cpp.d ${DEPEND_FOLDER}/camera.cpp.d ${DEPEND_FOLDER}/event.cpp.d ${DEPEND_FOLDER}/core_1.cpp.d ${DEPEND_FOLDER}/kernel.cpp.d ${DEPEND_FOLDER}/argument.cpp.d ${DEPEND_FOLDER}/map.cpp.d ${DEPEND_FOLDER}/renderer.cpp.d ${DEPEND_FOLDER}/build.cpp.d ${DEPEND_FOLDER}/function_x.cpp.d ${DEPEND_FOLDER}/engine_x.cpp.d ${DEPEND_FOLDER}/computer_x.cpp.d ${DEPEND_FOLDER}/initialize.cpp.d
LINK_DIRECTORY = 
LINK_LIBRARY = -l glfw -l glew -framework OpenGL -framework OpenCL

FLAG_OBJECT = `pkg-config --cflags glew` `pkg-config --cflags glfw3`
FLAG_EXECUTABLE = `pkg-config --libs glew` `pkg-config --libs glfw3`
FLAG_COMMON = -std=c++1z

#						BASIC RULES	

all : ${EXECUTABLE}

${EXECUTABLE} : ${OBJECT}
	${call INFO,Linking in executable ${EXECUTABLE}}
	@${COMPILER} ${FLAG_EXECUTABLE} ${FLAG_COMMON} ${LINK_DIRECTORY} ${LINK_LIBRARY} ${OBJECT} -o ${EXECUTABLE}

clean :
	${call INFO,Deleting objects' folder}
	@rm -rf ${OBJECT_FOLDER}
	${call INFO,Deleting dependencies' folder}
	@rm -rf ${DEPEND_FOLDER}

fclean : clean
	${call INFO,Deleting executable}
	@rm -rf ${EXECUTABLE}

re : fclean ${EXECUTABLE}

info :
	@echo "Objects :"
	@echo ${OBJECT}
	@echo "Depends :"
	@echo ${DEPEND}

.PHONY : clean fclean re info

#						OBJECTS
	
${OBJECT_FOLDER} :
	${call INFO,Creating objects' folder}
	@mkdir ${OBJECT_FOLDER}

${OBJECT_FOLDER}/main.cpp.o : ${DEPEND_FOLDER}/main.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,3%${COMMA} compiling object ../project/main.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/main.cpp.o -MF ${DEPEND_FOLDER}/main.cpp.d -c ../project/main.cpp -o ${OBJECT_FOLDER}/main.cpp.o

${OBJECT_FOLDER}/exception.cpp.o : ${DEPEND_FOLDER}/exception.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,7%${COMMA} compiling object ../project/common/exception.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/exception.cpp.o -MF ${DEPEND_FOLDER}/exception.cpp.d -c ../project/common/exception.cpp -o ${OBJECT_FOLDER}/exception.cpp.o

${OBJECT_FOLDER}/read_file.cpp.o : ${DEPEND_FOLDER}/read_file.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,10%${COMMA} compiling object ../project/common/read_file.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/read_file.cpp.o -MF ${DEPEND_FOLDER}/read_file.cpp.d -c ../project/common/read_file.cpp -o ${OBJECT_FOLDER}/read_file.cpp.o

${OBJECT_FOLDER}/core.cpp.o : ${DEPEND_FOLDER}/core.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,14%${COMMA} compiling object ../project/engine/core/core.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/core.cpp.o -MF ${DEPEND_FOLDER}/core.cpp.d -c ../project/engine/core/core.cpp -o ${OBJECT_FOLDER}/core.cpp.o

${OBJECT_FOLDER}/calculate_fps.cpp.o : ${DEPEND_FOLDER}/calculate_fps.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,17%${COMMA} compiling object ../project/engine/core/calculate_fps.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/calculate_fps.cpp.o -MF ${DEPEND_FOLDER}/calculate_fps.cpp.d -c ../project/engine/core/calculate_fps.cpp -o ${OBJECT_FOLDER}/calculate_fps.cpp.o

${OBJECT_FOLDER}/draw.cpp.o : ${DEPEND_FOLDER}/draw.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,21%${COMMA} compiling object ../project/engine/core/draw.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/draw.cpp.o -MF ${DEPEND_FOLDER}/draw.cpp.d -c ../project/engine/core/draw.cpp -o ${OBJECT_FOLDER}/draw.cpp.o

${OBJECT_FOLDER}/finish.cpp.o : ${DEPEND_FOLDER}/finish.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,25%${COMMA} compiling object ../project/engine/core/finish.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/finish.cpp.o -MF ${DEPEND_FOLDER}/finish.cpp.d -c ../project/engine/core/finish.cpp -o ${OBJECT_FOLDER}/finish.cpp.o

${OBJECT_FOLDER}/start.cpp.o : ${DEPEND_FOLDER}/start.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,28%${COMMA} compiling object ../project/engine/core/start.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/start.cpp.o -MF ${DEPEND_FOLDER}/start.cpp.d -c ../project/engine/core/start.cpp -o ${OBJECT_FOLDER}/start.cpp.o

${OBJECT_FOLDER}/glfw_callback_x.cpp.o : ${DEPEND_FOLDER}/glfw_callback_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,32%${COMMA} compiling object ../project/engine/core/glfw_callback_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/glfw_callback_x.cpp.o -MF ${DEPEND_FOLDER}/glfw_callback_x.cpp.d -c ../project/engine/core/glfw_callback_x.cpp -o ${OBJECT_FOLDER}/glfw_callback_x.cpp.o

${OBJECT_FOLDER}/launch_x.cpp.o : ${DEPEND_FOLDER}/launch_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,35%${COMMA} compiling object ../project/engine/core/launch_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/launch_x.cpp.o -MF ${DEPEND_FOLDER}/launch_x.cpp.d -c ../project/engine/core/launch_x.cpp -o ${OBJECT_FOLDER}/launch_x.cpp.o

${OBJECT_FOLDER}/receive_event.cpp.o : ${DEPEND_FOLDER}/receive_event.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,39%${COMMA} compiling object ../project/engine/core/receive_event.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/receive_event.cpp.o -MF ${DEPEND_FOLDER}/receive_event.cpp.d -c ../project/engine/core/receive_event.cpp -o ${OBJECT_FOLDER}/receive_event.cpp.o

${OBJECT_FOLDER}/shader.cpp.o : ${DEPEND_FOLDER}/shader.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,42%${COMMA} compiling object ../project/engine/shader/shader.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/shader.cpp.o -MF ${DEPEND_FOLDER}/shader.cpp.d -c ../project/engine/shader/shader.cpp -o ${OBJECT_FOLDER}/shader.cpp.o

${OBJECT_FOLDER}/uniform.cpp.o : ${DEPEND_FOLDER}/uniform.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,46%${COMMA} compiling object ../project/engine/uniform/uniform.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/uniform.cpp.o -MF ${DEPEND_FOLDER}/uniform.cpp.d -c ../project/engine/uniform/uniform.cpp -o ${OBJECT_FOLDER}/uniform.cpp.o

${OBJECT_FOLDER}/program.cpp.o : ${DEPEND_FOLDER}/program.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,50%${COMMA} compiling object ../project/engine/program/program.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/program.cpp.o -MF ${DEPEND_FOLDER}/program.cpp.d -c ../project/engine/program/program.cpp -o ${OBJECT_FOLDER}/program.cpp.o

${OBJECT_FOLDER}/vao.cpp.o : ${DEPEND_FOLDER}/vao.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,53%${COMMA} compiling object ../project/engine/vao/vao.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/vao.cpp.o -MF ${DEPEND_FOLDER}/vao.cpp.d -c ../project/engine/vao/vao.cpp -o ${OBJECT_FOLDER}/vao.cpp.o

${OBJECT_FOLDER}/buffer.cpp.o : ${DEPEND_FOLDER}/buffer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,57%${COMMA} compiling object ../project/engine/buffer/buffer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/buffer.cpp.o -MF ${DEPEND_FOLDER}/buffer.cpp.d -c ../project/engine/buffer/buffer.cpp -o ${OBJECT_FOLDER}/buffer.cpp.o

${OBJECT_FOLDER}/camera.cpp.o : ${DEPEND_FOLDER}/camera.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,60%${COMMA} compiling object ../project/engine/camera/camera.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/camera.cpp.o -MF ${DEPEND_FOLDER}/camera.cpp.d -c ../project/engine/camera/camera.cpp -o ${OBJECT_FOLDER}/camera.cpp.o

${OBJECT_FOLDER}/event.cpp.o : ${DEPEND_FOLDER}/event.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,64%${COMMA} compiling object ../project/engine/event/event.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/event.cpp.o -MF ${DEPEND_FOLDER}/event.cpp.d -c ../project/engine/event/event.cpp -o ${OBJECT_FOLDER}/event.cpp.o

${OBJECT_FOLDER}/core_1.cpp.o : ${DEPEND_FOLDER}/core_1.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,67%${COMMA} compiling object ../project/computer/core/core.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/core_1.cpp.o -MF ${DEPEND_FOLDER}/core_1.cpp.d -c ../project/computer/core/core.cpp -o ${OBJECT_FOLDER}/core_1.cpp.o

${OBJECT_FOLDER}/kernel.cpp.o : ${DEPEND_FOLDER}/kernel.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,71%${COMMA} compiling object ../project/computer/kernel/kernel.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/kernel.cpp.o -MF ${DEPEND_FOLDER}/kernel.cpp.d -c ../project/computer/kernel/kernel.cpp -o ${OBJECT_FOLDER}/kernel.cpp.o

${OBJECT_FOLDER}/argument.cpp.o : ${DEPEND_FOLDER}/argument.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,75%${COMMA} compiling object ../project/computer/argument/argument.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/argument.cpp.o -MF ${DEPEND_FOLDER}/argument.cpp.d -c ../project/computer/argument/argument.cpp -o ${OBJECT_FOLDER}/argument.cpp.o

${OBJECT_FOLDER}/map.cpp.o : ${DEPEND_FOLDER}/map.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,78%${COMMA} compiling object ../project/particle_system/map/map.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/map.cpp.o -MF ${DEPEND_FOLDER}/map.cpp.d -c ../project/particle_system/map/map.cpp -o ${OBJECT_FOLDER}/map.cpp.o

${OBJECT_FOLDER}/renderer.cpp.o : ${DEPEND_FOLDER}/renderer.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,82%${COMMA} compiling object ../project/particle_system/manager/renderer.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/renderer.cpp.o -MF ${DEPEND_FOLDER}/renderer.cpp.d -c ../project/particle_system/manager/renderer.cpp -o ${OBJECT_FOLDER}/renderer.cpp.o

${OBJECT_FOLDER}/build.cpp.o : ${DEPEND_FOLDER}/build.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,85%${COMMA} compiling object ../project/particle_system/manager/build.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/build.cpp.o -MF ${DEPEND_FOLDER}/build.cpp.d -c ../project/particle_system/manager/build.cpp -o ${OBJECT_FOLDER}/build.cpp.o

${OBJECT_FOLDER}/function_x.cpp.o : ${DEPEND_FOLDER}/function_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,89%${COMMA} compiling object ../project/particle_system/manager/function_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/function_x.cpp.o -MF ${DEPEND_FOLDER}/function_x.cpp.d -c ../project/particle_system/manager/function_x.cpp -o ${OBJECT_FOLDER}/function_x.cpp.o

${OBJECT_FOLDER}/engine_x.cpp.o : ${DEPEND_FOLDER}/engine_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,92%${COMMA} compiling object ../project/particle_system/manager/engine_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/engine_x.cpp.o -MF ${DEPEND_FOLDER}/engine_x.cpp.d -c ../project/particle_system/manager/engine_x.cpp -o ${OBJECT_FOLDER}/engine_x.cpp.o

${OBJECT_FOLDER}/computer_x.cpp.o : ${DEPEND_FOLDER}/computer_x.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,96%${COMMA} compiling object ../project/particle_system/manager/computer_x.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/computer_x.cpp.o -MF ${DEPEND_FOLDER}/computer_x.cpp.d -c ../project/particle_system/manager/computer_x.cpp -o ${OBJECT_FOLDER}/computer_x.cpp.o

${OBJECT_FOLDER}/initialize.cpp.o : ${DEPEND_FOLDER}/initialize.cpp.d | ${OBJECT_FOLDER} ${DEPEND_FOLDER}
	${call INFO,100%${COMMA} compiling object ../project/particle_system/manager/initialize.cpp}
	@${COMPILER} ${INCLUDE} ${FLAG_OBJECT} ${FLAG_COMMON} -MMD -MP -MT ${OBJECT_FOLDER}/initialize.cpp.o -MF ${DEPEND_FOLDER}/initialize.cpp.d -c ../project/particle_system/manager/initialize.cpp -o ${OBJECT_FOLDER}/initialize.cpp.o
	

#						DEPENDENCIES

${DEPEND_FOLDER} :
	${call INFO,Creating dependencies' folder}
	@mkdir ${DEPEND_FOLDER}
	
${DEPEND} :

include ${wildcard ${DEPEND}}	
