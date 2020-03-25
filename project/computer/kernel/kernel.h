#pragma once

#include "computer/namespace.h"
#include "computer/buffer/buffer.h"

class						computer::kernel
{
	friend class 			core;
public :
							kernel() = default;
							~kernel() = default;

	void					add_source(const std::string &file);

	void					build(const std::string &function, const int &number);
	void					run();

	buffer 					generate_buffer(const int &size, const memory_management &memory);
	void 					link_buffer(buffer &buffer);

	[[deprecated]]
	cl::CommandQueue		&read_command_queue()
	{
		return (queue);
	}

	[[deprecated]]
	cl::Kernel				&read_object()
	{
		return (object);
	}

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


