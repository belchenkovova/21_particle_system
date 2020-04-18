#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

void 				core::draw(draw_mode mode, const buffer &buffer)
{
	buffer.bind(true);
	glDrawArrays(static_cast<GLuint>(mode), 0, buffer.size);
	buffer.bind(false);
}