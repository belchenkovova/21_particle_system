#pragma once

#include "engine/namespace.h"
#include "engine/renderer/renderer.h"
#include "engine/timer/timer.h"
#include "engine/callback/callback.h"

class							engine::core final
{
public :

	inline static point			initial_window_size;
	inline static string		window_name;
	inline static glm::vec3		background = glm::vec3(0.f, 0.f, 0.f);
	inline static bool			use_blending = false;
	inline static bool			use_multisampling = false;
	inline static int			number_of_samples = 0;
	inline static bool 			should_render = false;

								core();
								~core();

	void 						attach_renderer(engine::renderer &renderer);

	template					<typename ...t_args>
	callback					&generate_callback(event::type type, t_args ...args)
	{
		return (callbacks.emplace_back(type, args...));
	}

	template					<typename ...t_args>
	timer						&generate_timer(float period, t_args ...args)
	{
		return (timers.emplace_back(period, args...));
	}

	void 						start();
	void 						finish();
	event						&receive_event();

	static void 				draw(draw_mode mode, const buffer &buffer);

	class 						settings
	{
	public :
		static void				fill_polygon(bool state);
		static void 			depth_test(bool state);
		static void				point_size(int value);
	};

	[[nodiscard]]
	static point				read_window_size()
	{
		return (window_size);
	}

protected :

	inline static int			instance_count = 0;
	inline static point			window_size;

	GLFWwindow					*window = nullptr;
	event						event;

	using						renderer_refence = reference_wrapper<renderer>;
	list<renderer_refence>		renderers;
	list<callback>				callbacks;
	list<timer>					timers;

	static void 				glfw_callback_key(GLFWwindow *window, int key, int code, int action, int mode);
	static void 				glfw_callback_mouse_movement(GLFWwindow *window, double x, double y);
	static void 				glfw_callback_mouse_key(GLFWwindow *window, int key, int action, int mode);

	void 						launch_callbacks();
	void 						launch_timers();
};


