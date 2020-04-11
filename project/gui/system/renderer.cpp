#include "system.h"

using namespace		gui;

					system::renderer::renderer(const objects_type &objects) :
					engine::renderer(false),
					objects(objects)
{}

void 				system::renderer::render()
{
	engine::core::settings::depth_test(false);
	for (const auto &object : objects)
		if (not object->is_latent)
			object->render();
}