#pragma once

#include "engine/namespace.h"
#include "engine/renderer/renderer.h"

class							engine::core final
{
public :

	inline static int			window_width{0};
	inline static int			window_height{0};
	inline static std::string	window_name;
	inline static int			point_size{2};
	inline static bool			use_depth_test{true};
	inline static bool			use_blending{true};
	inline static bool			use_multisampling{true};
	inline static bool 			should_render{true};

								core();
								~core();

	void 						attach_renderer(engine::renderer &renderer);

	template					<typename ...t_args>
	void						generate_timer(float period, t_args ...args)
	{
		timers.emplace_back(period, args...);
	}

	void 						start();
	void 						finish();

	static void 				draw(draw_mode mode, int count);

protected :

	using						renderer_refence = reference_wrapper<renderer>;

	inline static int			instance_count{0};
	GLFWwindow					*window{nullptr};
	int							width{0};
	int							height{0};

	vector<renderer_refence>	renderers;
	vector<callback>			callbacks;
	vector<timer>				timers;
};


