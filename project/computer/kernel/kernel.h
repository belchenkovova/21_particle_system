#pragma once

#include "computer/namespace.h"
#include "computer/argument/argument.h"

class						computer::kernel
{
	friend class 			core;
public :
							kernel() = default;
							~kernel() = default;

	void					add_source(const string &file);

	void					build(const string &function, const int &number);
	void					run();

	template 				<typename type, int group = 1>
	argument 				generate_argument(
							const int &size,
							const memory_management &memory = memory_management::read_write)
	{
		if (not is_built)
			throw (common::exception("Computer, Kernel : Object is not built"));
		return (computer::argument(context, queue, size * sizeof(type) * group, memory));
	}
	argument 				generate_argument(
							const engine::vbo::abstract &vbo,
							const memory_management &memory = memory_management::read_write);
	void 					link_argument(argument &argument);

private :

	bool 					is_built = false;

	string 					source;

	int						kernel_number = 0;
	int 					buffer_count = 0;

	const cl::Device		*device = nullptr;
	const cl::Context		*context = nullptr;
	cl::Program				program;
	cl::CommandQueue		queue;
	cl::Kernel				object;

							kernel(const cl::Device *device, const cl::Context *context);

	void 					compile_program();
	void 					set_queue();
	void 					set_kernel(const string &function);
};


