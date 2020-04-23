#include "particle_system/manager/manager.h"

using namespace		particle_system;

void				manager::build(const string &source)
{
	if (source.empty() and not exists(default_source))
		throw (common::exception("Particle System, Manager : Default map is not present"));
	else if (not source.empty() and not exists(source))
		throw (common::exception("Particle System, Manager : Bad map file"));

	map.emplace(source.empty() ? default_source : source);

	auto 			objects = map->receive_objects();
	auto 			settings = map->receive_settings();

	number_of_objects = objects.size();
	number_of_particles = settings.number_of_particles;
	start_color = settings.start_color;
	finish_color = settings.finish_color;
	engine::core::background = settings.background;

	renderer.build(number_of_particles);

	engine_build();
	computer_build();

	initialize(settings.initialization);
}