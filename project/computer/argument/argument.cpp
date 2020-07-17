#include "argument.h"

using namespace		computer;

					argument::argument(
					const cl::Context *context,
					const cl::CommandQueue &queue,
					const int &size,
					const memory_management &memory) :
					is_OpenGL_based(false),
					size(size),
					queue(&queue)
{
	object = cl::Buffer(*context, static_cast<unsigned int>(memory), size);
}

					argument::argument(
					const cl::Context *context,
					const cl::CommandQueue &queue,
					const engine::vbo::abstract &vbo,
					const memory_management &memory) :
					is_OpenGL_based(true),
					queue(&queue)
{
	object = cl::BufferGL(
		*context,
		static_cast<unsigned int>(memory),
		static_cast<cl_GLuint>(vbo.read_object()));
	vector.push_back(object.value());
}

void				argument::acquire()
{
	if (not is_OpenGL_based)
		throw (common::exception("Computer, Argument : Can't acquire argument"));
	if (not queue)
		throw (common::exception("Computer, Argument : Queue is nullptr"));
	queue->enqueueAcquireGLObjects(&vector);
}
void				argument::release()
{
	if (not is_OpenGL_based)
		throw (common::exception("Computer, Argument : Can't release argument"));
	if (not queue)
		throw (common::exception("Computer, Argument : Queue is nullptr"));
	queue->enqueueReleaseGLObjects(&vector);
}

void 				argument::read(void *host_ptr)
{
	if (not object)
		throw (common::exception("Computer, Argument : Argument is not initialized"));
	if (not size)
		throw (common::exception("Computer, Argument : Size is not defined"));
	queue->enqueueReadBuffer(*object, CL_TRUE, 0, *size, host_ptr);
}

void				argument::write(void *host_ptr)
{
	if (not object)
		throw (common::exception("Computer, Argument : Argument is not initialized"));
	if (not size)
		throw (common::exception("Computer, Argument : Size is not defined"));
	queue->enqueueWriteBuffer(*object, CL_TRUE, 0, *size, host_ptr);
}

void				argument::link(cl::Kernel &kernel, const int &index)
{
	if (not object)
		throw (common::exception("Computer, Argument : Argument is not initialized"));
	kernel.setArg(index, *object);
}