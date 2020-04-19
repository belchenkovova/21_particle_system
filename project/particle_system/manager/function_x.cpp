#include "particle_system/manager/manager.h"

using namespace			particle_system;

void 					manager::function_render()
{
//	kernels.attractor_execute.run();
//
//	kernels.repeller_execute.run();
//
//	kernels.emitter_start.run();
//	kernels.emitter_execute.run();
//	kernels.emitter_finish.run();
//
//	kernels.consumer_execute.run();

	arguments.position.acquire();
	kernels.particle_update.run();
	arguments.position.release();

	engine::core::should_render = true;
}

void 					manager::function_key()
{
	engine::event		&event = engine.receive_event();

	if (event.read_key() == engine::event::key::escape)
		engine.finish();
	else if (event.read_key() == engine::event::key::letter_a)
		renderer.camera.move(engine::axis::x, engine::sign::minus);
	else if (event.read_key() == engine::event::key::letter_d)
		renderer.camera.move(engine::axis::x, engine::sign::plus);
	else if (event.read_key() == engine::event::key::letter_w)
		renderer.camera.move(engine::axis::z, engine::sign::minus);
	else if (event.read_key() == engine::event::key::letter_s)
		renderer.camera.move(engine::axis::z, engine::sign::plus);
	else if (event.read_key() == engine::event::key::letter_q)
		renderer.camera.move(engine::axis::y, engine::sign::plus);
	else if (event.read_key() == engine::event::key::letter_e)
		renderer.camera.move(engine::axis::y, engine::sign::minus);
	else if (event.read_key() == engine::event::key::left)
		renderer.camera.rotate(engine::axis::y, engine::sign::plus);
	else if (event.read_key() == engine::event::key::right)
		renderer.camera.rotate(engine::axis::y, engine::sign::minus);
	else if (event.read_key() == engine::event::key::up)
		renderer.camera.rotate(engine::axis::x, engine::sign::plus);
	else if (event.read_key() == engine::event::key::down)
		renderer.camera.rotate(engine::axis::x, engine::sign::minus);
	else if (event.read_key() == engine::event::key::enter)
		timer->block = not timer->block;
	else
		return ;
	engine::core::should_render = true;
}