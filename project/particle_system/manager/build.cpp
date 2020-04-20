#include "particle_system/manager/manager.h"

using namespace		particle_system;

void				manager::build(const string &source)
{
#pragma message "Default scene"
	map.emplace(source.empty() ? "maps/demo_a.json" : source);

	auto 			objects = map->receive_objects();
	auto 			settings = map->receive_settings();

	number_of_objects = objects.size();
	number_of_particles = settings.number_of_particles;
	start_color = settings.start_color;
	finish_color = settings.finish_color;

	renderer.build(number_of_particles);

	engine_build();
	computer_build();

	initialize(settings.initialization);
}