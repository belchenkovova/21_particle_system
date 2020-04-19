#include "particle_system/manager/manager.h"

using namespace			particle_system;

void					manager::engine_build()
{
	timer = &engine.generate_timer(1.f / 100.f, &manager::function_render, this);
	timer->block = true;

	engine.generate_callback(engine::event::type::key_press, &manager::function_key, this);
	engine.generate_callback(engine::event::type::key_hold, &manager::function_key, this);
}