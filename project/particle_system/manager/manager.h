#pragma once

#include "particle_system/namespace.h"
#include "particle_system/map/map.h"

class						particle_system::manager
{
public :
							manager(engine::core &engine, computer::core &computer) :
							engine(engine), computer(computer) {}
							~manager() = default;

	void					build(const string &source = "");

	[[nodiscard]]
	engine::renderer		&receive_renderer()
	{
		return (renderer);
	}

private :

	engine::core			&engine;
	computer::core			&computer;

	int						number_of_objects = 0;
	int						number_of_particles = 0;
	vec3					start_color = vec3(0, 0, 0);
	vec3					finish_color = vec3(0, 0, 0);
	int						life_duration_min = 0;
	int						life_duration_max = 0;

	class 					renderer final : public engine::renderer
	{
	public :
							renderer() = default;
							~renderer() override = default;

		void				build(int number_of_particles);
		void 				render() override;

		using				engine::renderer::program;
		using				engine::renderer::buffer;

		engine::camera		camera;

		using				point_type = engine::vbo::real<float, 3>;
		using				point_ptr_type = std::shared_ptr<engine::vbo::real<float, 3>>;

		using				color_type = engine::vbo::real<float, 4>;
		using				color_ptr_type = std::shared_ptr<engine::vbo::real<float, 4>>;

		point_ptr_type		points;
		color_ptr_type		colors;
	}						renderer;

	optional<class map>		map;
	const string			default_source = "maps/default.json";

	class
	{
	public :
		computer::kernel	xorshift_seed;
		computer::kernel	particle_reset;
		computer::kernel	initialize_as_null;
		computer::kernel	initialize_as_sphere;
		computer::kernel	initialize_as_cube;
		computer::kernel	initialize_as_tetrahedron;
		computer::kernel	particle_update;
		computer::kernel	attractor_execute;
		computer::kernel	repeller_execute;
		computer::kernel	emitter_start;
		computer::kernel	emitter_finish;
		computer::kernel	emitter_execute;
		computer::kernel	consumer_execute;
	}						kernels;

	class
	{
	public :
		computer::argument	number_of_particles;
		computer::argument	number_of_objects;
		computer::argument	start_color;
		computer::argument	finish_color;
		computer::argument	life_duration_min;
		computer::argument	life_duration_max;
		computer::argument	object_type;
		computer::argument	object_position;
		computer::argument	object_power;
		computer::argument	is_alive;
		computer::argument	life_timer;
		computer::argument	position;
		computer::argument	velocity;
		computer::argument	acceleration;
		computer::argument	color;
		computer::argument	born_by_emitter;
		computer::argument	xorshift_state;
	}						arguments;

	void					engine_build();

	void					computer_build();
	void					computer_build_kernels();
	void					computer_build_arguments();
	void					computer_link_arguments();
	void					computer_fill_arguments();

	void 					function_work();
	void 					function_key_start();
	void 					function_key_finish();
	void					function_mouse_move();
	void					function_mouse_key();
	void					function_mouse_scroll();
	void					function_wait_for_work();
	void					function_wait_for_another_key();

	void					initialize(initialization method);

	engine::timer			*timer_work = nullptr;
	engine::timeout			*timeout_for_work = nullptr;
	engine::timeout			*timeout_for_another_key = nullptr;

	bool					was_camera_input = false;
	bool					was_key_input = false;

	int						controlled_object = 0;
	bool					control_lock = false;
};


