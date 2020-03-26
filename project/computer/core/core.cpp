#include "core.h"

using namespace					computer;

//								PUBLIC

								core::core() :
								use_OpenGL_local(use_OpenGL)
{
	set_platform();
	set_device();

	if (use_OpenGL)
	{
		CGLContextObj			gl_context = CGLGetCurrentContext();
		CGLShareGroupObj		share_group = CGLGetShareGroup(gl_context);

		cl_context_properties	properties[] = {
			CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE,
			(cl_context_properties) share_group, 0};

		set_context(properties);
	}
	else
		set_context(nullptr);
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

void 					core::set_context(cl_context_properties *properties)
{
	context = cl::Context(device, properties);
}
