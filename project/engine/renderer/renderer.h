#pragma once

#include "engine/namespace.h"
#include "engine/core/core.h"
#include "engine/program/program.h"
#include "engine/camera/camera.h"

class										engine::renderer :
											engine::core,
											engine::program,
											engine::camera
{
public :

	inline static std::string				vertex_source;
	inline static std::string				fragment_source;
	inline static glm::vec3					background{0.f, 0.f, 0.f};

											renderer();
											~renderer() override = default;

	void									loop();

	void									request_rendering();
	void									define_target(const buffer *target);

private :

	bool									is_rendering_requested{false};
	const buffer							*rendering_target{nullptr};

	void									render();
	static void								glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	vector<shared_ptr<callback::abstract>>	callbacks;
	vector<shared_ptr<callback::abstract>>	timer;
};


