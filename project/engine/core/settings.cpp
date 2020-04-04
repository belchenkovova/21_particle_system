#include "core.h"

using namespace		engine;

void 				core::settings::fill_polygon(bool state)
{
	if (state)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void 				core::settings::depth_test(bool state)
{
	if (state)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);
}

void				core::settings::point_size(int value)
{
	glPointSize(value);
}