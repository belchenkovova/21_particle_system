#pragma once

#include "engine/namespace.h"
#include "engine/renderer/renderers.h"
#include "engine/timer/timer.h"
#include "engine/callback/callback.h"
#include "engine/timeout/timeout.h"

class							engine::core final
{
public :

	inline static ivec2			initial_window_size;
	inline static string		window_name;
	inline static vec3			background = vec3(0.f, 0.f, 0.f);
	inline static bool			use_blending = false;
	inline static bool			use_multisampling = false;
	inline static bool			use_depth_test = false;
	inline static int			number_of_samples = 0;
	inline static bool 			should_render = false;
	inline static int 			point_size = 0;
	inline static bool			print_fps = false;
	inline static bool			reset_fps = false;

								core();
								~core();

	void 						attach_renderer(engine::renderer &renderer)
	{
		this->renderer = &renderer;
	}

	template					<typename ...t_args>
	callback					&generate_callback(t_args ...args)
	{
		return (callbacks.emplace_back(args...));
	}

	template					<typename ...t_args>
	timer						&generate_timer(t_args ...args)
	{
		return (timers.emplace_back(args...));
	}

	template					<typename ...t_args>
	timeout						&generate_timeout(t_args ...args)
	{
		return (timeouts.emplace_back(args...));
	}

	void 						start();
	void 						finish();
	event						&receive_event();

	static void 				draw(draw_mode mode, const buffer &buffer);

	[[nodiscard]]
	static double 				time()
	{
		return (glfwGetTime());
	}

	[[nodiscard]]
	static ivec2				read_window_size()
	{
		return (window_size);
	}

protected :

	inline static int			instance_count = 0;
	inline static ivec2			window_size;

	GLFWwindow					*window = nullptr;
	event						event;

	class renderer				*renderer = nullptr;
	list<callback>				callbacks;
	list<timer>					timers;
	list<timeout>				timeouts;

	static void 				glfw_callback_key(GLFWwindow *window, int key, int code, int action, int mode);
	static void 				glfw_callback_mouse_movement(GLFWwindow *window, double x, double y);
	static void 				glfw_callback_mouse_key(GLFWwindow *window, int key, int action, int mode);

	void 						launch_callbacks();
	void 						launch_timers();
	void 						launch_timeouts();

	static void 				calculate_fps();
};


