#include "particle_system/manager/manager.h"

using namespace		particle_system;

void				manager::build(const string &source)
{
#pragma message "Default scene"
	map.emplace(source.empty() ? "maps/demo_a.json" : source);

	number_of_objects = map->size();

	engine_build();
	computer_build();
}