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

		auto		font = gui.generate_font("project/resources/Courier New.ttf", 20);

		auto		button_alpha = gui.generate_button_with_label(functor_alpha, std::string("alpha"), font);
		auto		button_beta = gui.generate_button_with_label(functor_beta, std::string("beta"), font);
		auto		button_gamma = gui.generate_button_with_label(functor_gamma, std::string("gamma"), font);

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

		auto		pack = gui.generate_button_pack(gui::point(10, 10), gui::button_pack::activation_type::one);

		pack->body_color = glm::vec3(0.2f, 0.2f, 0.2f);
		pack->frame_color = glm::vec3(0.25f, 0.25f, 0.25f);
		pack->frame_width = 2;
		pack->spacing = 1;
		pack->indent = gui::point(10);

		pack->add_button(button_alpha);
		pack->add_button(button_beta);
		pack->add_button(button_gamma);
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
