#pragma once

#include "engine/namespace.h"
#include "engine/renderer/renderer.h"
#include "engine/timer/timer.h"
#include "engine/callback/callback.h"

class							engine::core final
{
public :

	inline static int			window_width{0};
	inline static int			window_height{0};
	inline static string		window_name{""};
	inline static glm::vec3		background{0.f, 0.f, 0.f};
	inline static bool			use_blending{true};
	inline static bool			use_multisampling{true};
	inline static bool 			should_render{true};

								core();
								~core();

	[[deprecated]] GLFWwindow	*read_window() const {return (window);}

	void 						attach_renderer(const engine::renderer::pure &renderer);

	template					<typename ...t_args>
	void						generate_callback(event::type type, t_args ...args)
	{
		callbacks.emplace_back(type, args...);
	}

	template					<typename ...t_args>
	void						generate_timer(float period, t_args ...args)
	{
		timers.emplace_back(period, args...);
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
	int 						read_width() const;
	[[nodiscard]]
	int 						read_height() const;

protected :

	inline static int			instance_count{0};
	GLFWwindow					*window{nullptr};
	int							final_width{0};
	int							final_height{0};
	event						event;

	using						renderer_refence = reference_wrapper<const renderer::pure>;
	vector<renderer_refence>	renderers;
	vector<callback>			callbacks;
	vector<timer>				timers;

	static void 				glfw_callback_key(GLFWwindow *window, int key, int code, int action, int mode);
	static void 				glfw_callback_mouse_movement(GLFWwindow *window, double x, double y);
	static void 				glfw_callback_mouse_key(GLFWwindow *window, int key, int action, int mode);

	void 						launch_callbacks();
	void 						launch_timers();
};


