#pragma once

#include "computer/namespace.h"
#include "computer/kernel/kernel.h"

#define OPENCL_X_OPENGL

class							computer::core
{
public :
								core();
								~core() = default;

	kernel						generate_kernel();

	[[deprecated]]
	const cl::Context			&read_context()
	{
		return (context);
	}

private :

	cl::Platform				platform;
	cl::Device					device;
	cl::Context					context;

	void 						set_platform();
	void 						set_device();
	void 						set_context();

};