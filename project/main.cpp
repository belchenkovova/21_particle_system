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
		engine::core::background = glm::vec3(.9f, .9f, .9f);

		engine::camera::start_position = glm::vec3(0.f, 0.f, 5.f);
		engine::camera::movement_speed = .1f;
		engine::camera::rotation_speed = .1f;
		engine::camera::near_plane = .1f;
		engine::camera::far_plane = 1000.f;

		computer::core::use_OpenGL = true;

		gui::button::body_color = glm::vec3(0.75f, 0.75f, 0.75f);
		gui::button::frame_color = glm::vec3(0.8f, 0.8f, 0.8f);
		gui::button::frame_width = 2;

		gui::button_with_label::indent = gui::point(25);

		particle_system::number_of_particles = 100 * 100;
	}

	void			setup_dynamic()
	{
		engine::core::settings::depth_test(true);
		engine::core::settings::point_size(5);

		engine.attach_renderer(system.receive_particle_renderer());
		engine.attach_renderer(system.receive_cube_renderer());
		engine.attach_renderer(gui.receive_renderer());
	}

	void			setup_gui()
	{
		auto		functor_hi  = engine::functor([](){ std::cout << "Hi" << std::endl; });
		auto		functor_bye = engine::functor([](){ std::cout << "Bye" << std::endl; });

		auto		font_a = gui.generate_font("project/resources/HelveticaNeue.ttc", 50);
		auto		font_b = gui.generate_font("project/resources/HelveticaNeue.ttc", 40);

		auto		button_hi = gui.generate_button_with_label(functor_hi, std::string("Hi"), font_a);
		auto		button_bye = gui.generate_button_with_label(functor_bye, std::string("Bye"), font_b);

		auto		pack = gui.generate_horizontal_pack(gui::point(10, 10));

		pack->add_item(button_hi);
		pack->add_item(button_bye);
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
