#pragma once

#include "computer/namespace.h"

enum class						computer::memory_management : unsigned int
{
	read_only = CL_MEM_READ_ONLY,
	write_only = CL_MEM_WRITE_ONLY,
	read_write = CL_MEM_READ_WRITE
};

class							computer::argument
{
	friend class 				kernel;

public :
								argument() = default;
								~argument() = default;

	void						acquire();
	void						release();

	void						write(void *host_ptr);

private :

	bool						is_OpenGL_based = false;
	std::optional<int>			size;
	std::optional<cl::Buffer>	object;
	vector<cl::Memory>			vector;
	const cl::CommandQueue		*queue = nullptr;

								argument(
								const cl::Context *context,
								const cl::CommandQueue &queue,
								const int &size,
								const memory_management &memory);
								argument(
								const cl::Context *context,
								const cl::CommandQueue &queue,
								const engine::vbo::abstract &vbo,
								const memory_management &memory);

	void						link(cl::Kernel &kernel, const int &index);
};


