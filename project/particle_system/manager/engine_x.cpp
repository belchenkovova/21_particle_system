#include "particle_system/manager/manager.h"

using namespace			particle_system;

void					manager::engine_start()
{
	timer = &engine.generate_timer(1.f / 100.f, &manager::timer_function, this);
	timer->block = true;

	engine.generate_callback(engine::event::type::key_press, &manager::callback_function, this);
	engine.generate_callback(engine::event::type::key_hold, &manager::callback_function, this);
}