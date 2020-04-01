#include "system.h"

using namespace		gui;

					system::system(engine::core &engine) :
					engine(engine),
					text_renderer(engine)
{
	engine::core::should_render = true;
	engine.attach_renderer(text_renderer);
}