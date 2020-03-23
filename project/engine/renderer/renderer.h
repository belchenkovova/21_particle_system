#pragma once

#include "engine/namespace.h"
#include "engine/core/core.h"
#include "engine/program/program.h"
#include "engine/buffer/buffer.h"
#include "engine/camera/camera.h"

class							engine::renderer :
								engine::core,
								engine::program,
								engine::buffer,
								engine::camera
{
public :

	inline static std::string	vertex_source;
	inline static std::string	fragment_source;
	inline static glm::vec3		background{0.f, 0.f, 0.f};

								renderer();
								~renderer() override = default;

	[[nodiscard]]
	engine::buffer				&receive_buffer();

	void						loop();
	void						request_render();

private :

	bool						render_request{false};

	void						render();
};


