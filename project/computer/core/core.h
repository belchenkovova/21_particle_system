#pragma once

#include "computer/namespace.h"
#include "computer/kernel/kernel.h"

class							computer::core
{
public :

	static inline bool			use_OpenGL = false;

								core();
								~core() = default;

	kernel						generate_kernel();

private :

	inline static int			instance_count = 0;
	cl::Platform				platform;
	cl::Device					device;
	cl::Context					context;

	void 						set_platform();
	void 						set_device();
	void 						set_context(cl_context_properties *properties);

};