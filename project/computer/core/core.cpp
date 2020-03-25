#include "core.h"

using namespace					computer;

#pragma OPENCL EXTENSION CL_APPLE_gl_sharing : enable

//								PUBLIC

#include <OpenCL/opencl.h>
#include <OpenGL/OpenGL.h>

								core::core()
{
	CGLContextObj glContext = CGLGetCurrentContext();
	CGLShareGroupObj shareGroup = CGLGetShareGroup(glContext);

	cl_context_properties properties[] = {
		CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE,
		(cl_context_properties)shareGroup,
		0};

	set_platform();
	set_device();
#ifdef OPENCL_X_OPENGL
	context = cl::Context(device, properties);
#else
	set_context();
#endif
}

kernel						core::generate_kernel()
{
	return (kernel(&device, &context));
}

//								PRIVATE

void 							core::set_platform()
{
	std::vector<cl::Platform>	platform_array;

	cl::Platform::get(&platform_array);
	platform = platform_array[0];

}

void 							core::set_device()
{
	std::vector<cl::Device>		device_array;

	platform.getDevices(CL_DEVICE_TYPE_GPU, &device_array);
	device = device_array[0];

}

void 					core::set_context()
{
	context = cl::Context(device);
}
