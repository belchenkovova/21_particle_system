#include "kernel.h"

using namespace				computer;

//							PUBLIC

void						kernel::add_source(const string &file)
{
	source += common::read_file(file);
	source += "\n\n";
}

void						kernel::build(const string &function, const int &number)
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

argument 					kernel::generate_argument(const engine::vbo::abstract &vbo, const memory_management &memory)
{
	if (not is_built)
		throw (common::exception("Computer, Kernel : Object is not built"));
	return (computer::argument(context, queue, vbo, memory));
}

void 						kernel::link_argument(argument &argument)
{
	if (not is_built)
		throw (common::exception("Computer, Kernel : Object is not built"));
	argument.link(object, buffer_count++);
}

//							PRIVATE

							kernel::kernel(const cl::Device *device, const cl::Context *context)
{
	this->device = device;
	this->context = context;
}

void 						kernel::compile_program()
{
	string				log;

	program = cl::Program(*context, source);
	if(program.build({*device}) != CL_SUCCESS)
	{
		log = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(*device);

		std::cout << "Source" << std::endl;
		std::cout << source << std::endl;

		std::cerr << "Compilation log" << std::endl;
		std::cerr << log << std::endl;

		throw (common::exception("Computer, Kernel : Compilation error"));
	}
}

void 						kernel::set_queue()
{
	queue = cl::CommandQueue(*context, *device);
}

void 						kernel::set_kernel(const string &function)
{
	object = cl::Kernel(program, function.c_str());
}
