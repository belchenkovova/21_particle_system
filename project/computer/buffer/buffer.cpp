#include "computer/buffer/buffer.h"


using namespace		computer;

					buffer::buffer(
					const cl::Context *context,
					const cl::CommandQueue *queue,
					const int &size,
					const memory_management &memory) :
					queue(queue)
{
	this->size = size;
	object = cl::Buffer(*context, static_cast<unsigned int>(memory), size);
	is_built = true;
}

void				buffer::link(cl::Kernel kernel, const int &index)
{
	if (not is_built)
		throw (common::exception("Computer, Argument : Object is not built"));
	kernel.setArg(index, object);
	is_linked = true;
}

void 				buffer::read(void *ptr)
{
	queue->enqueueReadBuffer(object, CL_TRUE, 0, size, ptr);
}

void 				buffer::write(void *ptr)
{
	queue->enqueueWriteBuffer(object, CL_TRUE, 0, size, ptr);
}
