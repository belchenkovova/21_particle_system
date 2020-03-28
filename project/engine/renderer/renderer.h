#pragma once

#include "engine/namespace.h"
#include "engine/core/core.h"
#include "engine/program/program.h"
#include "engine/camera/camera.h"
#include "engine/callbacks/timer.h"

class								engine::renderer :
									engine::core,
									engine::program,
									engine::camera
{
public :

	inline static std::string		vertex_source;
	inline static std::string		fragment_source;
	inline static glm::vec3			background{0.f, 0.f, 0.f};

									renderer();
									~renderer() override = default;

	void							loop();

	void							request_rendering();
	void							define_target(const buffer *target);

	template						<typename ... t_args>
	void							add_timer(float period, t_args ...args)
	{
		timers.push_back(make_shared<timer>(period, args...));
	}

private :

	bool							is_rendering_requested{false};
	const buffer					*rendering_target{nullptr};

	void							render();
	static void						glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	vector<shared_ptr<callback>>	callbacks;
	vector<shared_ptr<timer>>		timers;
};


