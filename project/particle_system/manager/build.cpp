#include "particle_system/manager/manager.h"

using namespace		particle_system;

void				manager::build(const string &source)
{
#pragma message "Default scene"
	map.emplace(source.empty() ? "maps/demo_a.json" : source);

	number_of_objects = map->receive_objects().size();
	number_of_particles = map->receive_settings().number_of_particles;
	particle_color = map->receive_settings().particle_color;

	renderer.build(number_of_particles);

	engine_build();
	computer_build();
}