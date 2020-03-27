#pragma once

#include "computer/namespace.h"
#include "computer/argument/argument.h"

class						computer::kernel
{
	friend class 			core;
public :
							kernel() = default;
							~kernel() = default;

	void					add_source(const std::string &file);

	void					build(const std::string &function, const int &number);
	void					run();

	argument 				generate_argument(
							const int &size,
							const memory_management &memory = memory_management::read_write);
	argument 				generate_argument(
							const engine::vbo::abstract &vbo,
							const memory_management &memory = memory_management::read_write);
	void 					link_argument(argument &argument);

private :

	bool 					is_built = false;

	std::string 			source;

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
	void 					set_kernel(const std::string &function);
};


