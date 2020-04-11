#include "engine/engine.h"
#include "computer/computer.h"
#include "gui/gui.h"
#include "particle_system/particle_system.h"

class				final
{
public :

					final() = default;
					~final() = default;

	static void		setup_static()
	{
		engine::core::window_width = 1280;
		engine::core::window_height = 720;
		engine::core::window_name = "Particle System";
		engine::core::background = glm::vec3(.05f, .05f, .05f);
		engine::core::use_multisampling = false;
		engine::core::number_of_samples = 0;
		engine::core::use_blending = true;

		engine::camera::start_position = glm::vec3(0.f, 0.f, 5.f);
		engine::camera::movement_speed = .1f;
		engine::camera::rotation_speed = .1f;
		engine::camera::near_plane = .1f;
		engine::camera::far_plane = 1000.f;

		computer::core::use_OpenGL = true;

		particle_system::number_of_particles = 100 * 100;
	}

	void			setup_dynamic()
	{
		engine::core::settings::point_size(2);
		engine::core::should_render = true;

		engine.attach_renderer(system.receive_particle_renderer());
		engine.attach_renderer(system.receive_cube_renderer());
		engine.attach_renderer(gui.receive_renderer());
	}

	void			setup_gui()
	{
		auto		functor_alpha  = engine::functor([](){ std::cout << "Alpha" << std::endl; });
		auto		functor_beta = engine::functor([](){ std::cout << "Beta" << std::endl; });
		auto		functor_gamma = engine::functor([](){ std::cout << "Gamma" << std::endl; });
		auto		functor_delta = engine::functor([](){ std::cout << "Delta" << std::endl; });
		auto		functor_epsilon = engine::functor([](){ std::cout << "Epsilon" << std::endl; });

		auto		font = gui.generate_font("project/resources/Courier New.ttf", 20);

		auto		button_alpha = gui.generate_button_with_label(functor_alpha, std::string("alpha"), font);
		auto		button_beta = gui.generate_button_with_label(functor_beta, std::string("beta"), font);
		auto		button_gamma = gui.generate_button_with_label(functor_gamma, std::string("gamma"), font);
		auto		button_delta = gui.generate_button_with_label(functor_delta, std::string("delta"), font);
		auto		button_epsilon = gui.generate_button_with_label(functor_delta, std::string("epsilon"), font);

		auto 		setup_button = [](gui::button_with_label &button)
		{
			button.body_color = glm::vec3(0.3f, 0.3f, 0.3f);
			button.frame_color = glm::vec3(0.35f, 0.35f, 0.35f);
			button.frame_width = 2;
			button.active_color = glm::vec4(0.f, 0.f, 0.5f, 0.5f);
			button.indent = gui::point(25);
		};

		setup_button(*button_alpha);
		setup_button(*button_beta);
		setup_button(*button_gamma);
		setup_button(*button_delta);
		setup_button(*button_epsilon);

		auto		button_pack_higher = gui.generate_button_pack(gui::button_pack::activation_type::one);

		button_pack_higher->body_color = glm::vec3(0.2f, 0.2f, 0.2f);
		button_pack_higher->frame_color = glm::vec3(0.25f, 0.25f, 0.25f);
		button_pack_higher->frame_width = 2;
		button_pack_higher->spacing = 1;
		button_pack_higher->indent = gui::point(10);

		button_pack_higher->add_button(button_alpha);
		button_pack_higher->add_button(button_beta);
		button_pack_higher->add_button(button_gamma);

		auto		button_pack_lower = gui.generate_button_pack(gui::button_pack::activation_type::one);

		button_pack_lower->id = 8;

		button_pack_lower->body_color = glm::vec3(0.2f, 0.2f, 0.2f);
		button_pack_lower->frame_color = glm::vec3(0.25f, 0.25f, 0.25f);
		button_pack_lower->frame_width = 2;
		button_pack_lower->spacing = 1;
		button_pack_lower->indent = gui::point(10);

		button_pack_lower->add_button(button_delta);
		button_pack_lower->add_button(button_epsilon);

		auto		vertical_pack = gui.generate_vertical_pack(gui::point());

		vertical_pack->body_color = glm::vec3(1.f, 0.f, 0.f);
		vertical_pack->frame_color = glm::vec3(0.25f, 0.25f, 0.25f);
		vertical_pack->frame_width = 2;
		vertical_pack->spacing = 1;
		vertical_pack->indent = gui::point(10);

		vertical_pack->add_item(button_pack_higher);
		vertical_pack->add_item(button_pack_lower);
	}

	void			start()
	{
		engine.start();
	}

private :

	engine::core	engine;
	computer::core	computer;
	gui::system		gui = gui::system(engine);
	particle_system	system = particle_system(engine, computer);
};

int					main()
{
	try
	{
		final		*final = nullptr;

		final::setup_static();
		final = new class final;
		final->setup_dynamic();
		final->setup_gui();
		final->start();
		delete final;
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}
