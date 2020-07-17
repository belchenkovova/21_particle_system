#include "engine/engine.h"
#include "computer/computer.h"
#include "particle_system/particle_system.h"
#include "external/CLI11.hpp"

class							final
{
public :
								final() = default;
								~final() = default;

	bool						process_options(int argc, char **argv)
	{
		std::string				demo_string;
		std::string				map_string;
		std::string				resolution_string;

		auto					app = CLI::App("");

		app.set_help_flag();

		app.add_option("--demo", demo_string);
		app.add_option("--map", map_string);
		app.add_option("--resolution", resolution_string);

		auto					flag_help = app.add_flag("--help");
		auto					flag_fps = app.add_flag("--fps");
		auto					flag_fast = app.add_flag("--fast");

		try
		{
			app.parse(argc, argv);
		}
		catch (const CLI::ParseError &)
		{
			throw (common::exception("Final : Invalid flags, use --help"));
		}

		if (*flag_help)
		{
			std::cout
				<< std::endl
				<< "Particle system " << std::endl
				<< std::endl
				<< "Flags : " << std::endl
				<< "--demo=[demo letter] : choose a demo map (a-d)" << std::endl
				<< "--map=[map file] : specify JSON file used by program as map" << std::endl
				<< "--resolution=[width],[height] : set resolution of window" << std::endl
				<< "--fps : display FPS" << std::endl
				<< "--fast : lower quality, increase performance" << std::endl
				<< "--help : get list flags and keys" << std::endl
				<< std::endl
				<< "Controls : " << std::endl
				<< "w/a/s/d/q/e : camera position control" << std::endl
				<< "left/right/up/down : camera direction control" << std::endl
				<< "enter : pause/continue particle system movement" << std::endl
				<< "mouse movement : move selected object in xy axes" << std::endl
				<< "mouse scroll : move selected object in z axis" << std::endl
				<< "left mouse click : go to previous object" << std::endl
				<< "right mouse click : go to next object" << std::endl
				<< "1 : initialize particles as sphere" << std::endl
				<< "2 : initialize particles as cube" << std::endl
				<< "3 : initialize particles as tetrahedron" << std::endl
				<< "0 : hide all particles" << std::endl
				<< std::endl;
			return (false);
		}

		fps = *flag_fps ? true : false;
		fast = *flag_fast ? true : false;

		if (not demo_string.empty())
			map = "maps/demo_" + demo_string + ".json";
		else
			map = map_string;

		if (not resolution_string.empty())
		{
			std::stringstream	stream(resolution_string);

			auto				extract_int = [&stream]()
			{
				int value;

				if ((stream >> value).fail())
					throw (common::exception("Final : Bad resolution value"));
				return (value);
			};

			resolution.emplace();
			resolution->x = extract_int();
			if (stream.peek() != ',')
				throw (common::exception("Final : Bad resolution pattern"));
			stream.ignore();
			resolution->y = extract_int();
		}

		return (true);
	}

	void						setup_static()
	{
		engine::core::initial_window_size = resolution ? *resolution : engine::ivec2(1280, 720);
		engine::core::window_name = "Particle system";
		engine::core::use_blending = true;
		engine::core::use_depth_test = true;
		engine::core::point_size = 1;
		engine::core::should_render = true;

		engine::core::print_fps = fps;
		engine::core::use_multisampling = not fast;
		engine::core::number_of_samples = 4;

		engine::camera::start_position = engine::vec3(0.f, 0.f, 2500.f);
		engine::camera::movement_speed = 10.f;
		engine::camera::rotation_speed = .3f;
		engine::camera::near_plane = 10.f;
		engine::camera::far_plane = 20000.f;

		computer::core::use_OpenGL = true;

		particle_system::fast = fast;
	}

	void						setup_dynamic()
	{
		engine.emplace();
		computer.emplace();
		system.emplace(*engine, *computer);

		engine->attach_renderer(system->receive_renderer());
		system->build(map);
	}

	void						run()
	{
		engine->start();
	}

private :

	using						engine_type = std::optional<engine::core>;
	using						computer_type = std::optional<computer::core>;
	using						system_type = std::optional<particle_system::manager>;

	std::string					map;
	std::optional<glm::ivec2>	resolution;

	engine_type					engine;
	computer_type				computer;
	system_type					system;

	bool						fps = false;
	bool						fast = false;
};

int								main(int argc, char **argv)
{
	try
	{
		final					final;

		if (!final.process_options(argc, argv))
			return (0);

		final.setup_static();
		final.setup_dynamic();
		final.run();
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle system error" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}
