#pragma once

#include "computer/namespace.h"

enum class					computer::memory_management : unsigned int
{
	read_only = CL_MEM_READ_ONLY,
	write_only = CL_MEM_WRITE_ONLY,
	read_write = CL_MEM_READ_WRITE
};

class						computer::buffer
{
	friend class 			kernel;

public :

							buffer() = default;
							~buffer() = default;

	[[deprecated]]
	void 					read(void *ptr);
	[[deprecated]]
	void 					write(void *ptr);

private :

	bool 					is_built{false};
	bool					is_linked{false};

	const cl::CommandQueue	*queue{nullptr};
	cl::Buffer				object;
	int 					size{0};

							buffer(
							const cl::Context *context,
							const cl::CommandQueue *queue,
							const int &size,
							const memory_management &memory);
	void					link(cl::Kernel kernel, const int &index);
};


