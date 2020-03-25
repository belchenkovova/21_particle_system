#include "kernel.h"

using namespace				computer;

//							PUBLIC

void						kernel::add_source(const std::string &file)
{
	source += common::read_file(file);
	source += "\n\n";
}

void						kernel::build(const std::string &function, const int &number)
{
	kernel_number = number;

	compile_program();
	set_queue();
	set_kernel(function);

	is_built = true;
}


void 						kernel::run()
{
	if (not is_built)
		throw (common::exception("Computer, Kernel : Object is not built"));
	queue.enqueueNDRangeKernel(object, cl::NullRange, cl::NDRange(kernel_number), cl::NullRange);
	queue.finish();
}

buffer 						kernel::generate_buffer(const int &size, const memory_management &memory)
{
	buffer					buffer;

	if (not is_built)
		throw (common::exception("Computer, Kernel : Object is not built"));
	buffer = computer::buffer(context, &queue, size, memory);
	return (buffer);
}

void 						kernel::link_buffer(buffer &buffer)
{
	if (not is_built)
		throw (common::exception("Computer, Kernel : Object is not built"));
	buffer.link(object, buffer_count++);
}

//							PRIVATE

							kernel::kernel(const cl::Device *device, const cl::Context *context)
{
	this->device = device;
	this->context = context;
}

void 						kernel::compile_program()
{
	std::string				log;

	program = cl::Program(*context, source);
	if(program.build({*device}) != CL_SUCCESS)
	{
		log = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(*device);

		printf("Log : %s\n", log.c_str());
		throw (common::exception("Computer, Kernel : Compilation error"));
	}
}

void 						kernel::set_queue()
{
	queue = cl::CommandQueue(*context, *device);
}

void 						kernel::set_kernel(const std::string &function)
{
	object = cl::Kernel(program, function.c_str());
}
