#pragma once

#include "engine/namespace.h"
#include "engine/program/program.h"
#include "engine/buffer/buffer.h"

namespace				engine::renderer
{
	class				pure
	{
	public :
						pure() = default;
		virtual			~pure() = default;

		virtual void	render() const = 0;
	};

	class				OpenGL : public pure
	{
	public :
						OpenGL() = default;
						~OpenGL() override = default;
	protected :

		program			program;
		buffer			buffer;
	};
}

