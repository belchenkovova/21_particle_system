#include "button.h"

using namespace		gui;

					button::button(const class functor &functor) :
					space(true)
{
	functors.pressed = functor;
}

void				button::render() const
{
	assert(renderer);

	float			data[] =
	{
		(float)min.x, (float)min.y,
		(float)min.x, (float)max.y,
		(float)max.x, (float)max.y,
		(float)max.x, (float)min.y
	};

	for (int i = 0; i < 8; i++)
		renderer->points->at(i) = data[i];
	renderer->points->save();

	renderer->render();
}
