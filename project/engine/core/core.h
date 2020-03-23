#pragma once

#include "engine/namespace.h"

class							engine::core
{
public :

	inline static int			window_width{0};
	inline static int			window_height{0};
	inline static std::string	window_name;
	inline static int			point_size{2};
	inline static bool			use_depth_test{true};
	inline static bool			use_blending{true};
	inline static bool			use_multisampling{true};

								core();
	virtual						~core();

protected :

	inline static int			instance_count{0};

	GLFWwindow					*window{nullptr};
	int							width{0};
	int							height{0};
};


