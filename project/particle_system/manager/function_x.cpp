#include "particle_system/manager/manager.h"

using namespace			particle_system;

void 					manager::function_work()
{
	arguments.position.acquire();

	kernels.attractor_execute.run();
	kernels.repeller_execute.run();

	if (not fast)
	{
		kernels.emitter_start.run();
		kernels.emitter_execute.run();
		kernels.emitter_finish.run();
	}

	kernels.particle_update.run();

	if (not fast)
		kernels.consumer_execute.run();

	arguments.position.release();

	engine::core::should_render = true;
}

void 					manager::function_key_start()
{
	engine::event		&event = engine.receive_event();

	was_key_input = true;
	if (event.read_key() == engine::key::escape)
		engine.finish();
	else if (event.read_key() == engine::key::letter_a)
		renderer.camera.move(engine::axis::x, engine::sign::minus);
	else if (event.read_key() == engine::key::letter_d)
		renderer.camera.move(engine::axis::x, engine::sign::plus);
	else if (event.read_key() == engine::key::letter_w)
		renderer.camera.move(engine::axis::z, engine::sign::minus);
	else if (event.read_key() == engine::key::letter_s)
		renderer.camera.move(engine::axis::z, engine::sign::plus);
	else if (event.read_key() == engine::key::letter_q)
		renderer.camera.move(engine::axis::y, engine::sign::plus);
	else if (event.read_key() == engine::key::letter_e)
		renderer.camera.move(engine::axis::y, engine::sign::minus);
	else if (event.read_key() == engine::key::left)
		renderer.camera.rotate(engine::axis::y, engine::sign::plus);
	else if (event.read_key() == engine::key::right)
		renderer.camera.rotate(engine::axis::y, engine::sign::minus);
	else if (event.read_key() == engine::key::up)
		renderer.camera.rotate(engine::axis::x, engine::sign::plus);
	else if (event.read_key() == engine::key::down)
		renderer.camera.rotate(engine::axis::x, engine::sign::minus);
	else if (event.read_key() == engine::key::enter)
		timer_work->block(not timer_work->is_blocked());
	else if (event.read_key() == engine::key::number_1)
		initialize(initialization::sphere);
	else if (event.read_key() == engine::key::number_2)
		initialize(initialization::cube);
	else if (event.read_key() == engine::key::number_3)
		initialize(initialization::tetrahedron);
	else if (event.read_key() == engine::key::number_0)
		initialize(initialization::null);
	else
		return ;

	if (event.read_key() == engine::key::letter_a or
		event.read_key() == engine::key::letter_d or
		event.read_key() == engine::key::letter_w or
		event.read_key() == engine::key::letter_s or
		event.read_key() == engine::key::letter_q or
		event.read_key() == engine::key::letter_e or
		event.read_key() == engine::key::left or
		event.read_key() == engine::key::right or
		event.read_key() == engine::key::up or
		event.read_key() == engine::key::down)
	{

		timer_work->block_reserved(true);
		was_camera_input = true;
	}

	if (event.read_key() == engine::key::number_1 or
		event.read_key() == engine::key::number_2 or
		event.read_key() == engine::key::number_3 or
		event.read_key() == engine::key::number_0)
		timer_work->block_reserved(true);

	engine::core::should_render = true;
}

void 					manager::function_key_finish()
{
	if (not was_camera_input)
	{
		engine::core::should_render = true;
		return ;
	}

	timeout_for_another_key->use();

	was_camera_input = false;
	was_key_input = false;
}

void					manager::function_mouse_move()
{
	auto				mouse_position = engine.receive_event().read_mouse();
	float				position_data[number_of_objects * 3];

	static float		window_ratio = (float)engine::core::initial_window_size.x / engine::core::initial_window_size.y;
	constexpr float		distance_multiplier = 0.535f;

	assert(controlled_object < number_of_objects);
	arguments.object_position.read(&position_data);

	auto				&camera = renderer.camera;
	vec3				position = vec3(0.f);

	for (int i = 0; i < 3; i++)
		position[i] = position_data[controlled_object * 3 + i];

	const float			distance_to_camera = camera.distance_to_point(position);
	const float			offset_multiplier = distance_multiplier * distance_to_camera;

	position = camera.read_position() + camera.read_front() * distance_to_camera;
	position += camera.read_right() * mouse_position.x * window_ratio * offset_multiplier;
	position += camera.read_up() * mouse_position.y * offset_multiplier;

	for (int i = 0; i < 3; i++)
		position_data[controlled_object * 3 + i] = position[i];

	arguments.object_position.write(&position_data);
}

void					manager::function_wait_for_work()
{
	timer_work->block_reserved(false);
	engine::core::should_render = true;
}

void					manager::function_wait_for_another_key()
{
	if (not was_key_input)
	{
		timer_work->block_reserved(false);
		engine::core::should_render = true;
	}
}