#include "particle_system/manager/manager.h"

using namespace			particle_system;

void					manager::engine_build()
{
	timer_work = &engine.generate_timer(1.f / 70.f, &manager::function_work, this);
	timer_work->block_reserved(true);

	engine.generate_callback(engine::event::type::key_press, &manager::function_key_start, this);
	engine.generate_callback(engine::event::type::key_hold, &manager::function_key_start, this);
	engine.generate_callback(engine::event::type::key_release, &manager::function_key_finish, this);
	engine.generate_callback(engine::event::type::mouse_move, &manager::function_mouse_move, this);

	timeout_for_work = &engine.generate_timeout(1.0f, &manager::function_wait_for_work, this);
	timeout_for_another_key = &engine.generate_timeout(1.0f, &manager::function_wait_for_another_key, this);
}