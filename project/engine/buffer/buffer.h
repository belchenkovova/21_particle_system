#pragma once

#include "engine/namespace.h"
#include "engine/vbo/vbo.h"
#include "engine/vao/vao.h"

class						engine::buffer final : private engine::vao
{
public :

							buffer() = default;
							~buffer() override = default;

	using					engine::vao::generate_attribute;
	using					engine::vao::receive_attribute;

	void					resize(int size);
	void					bind(bool state);
	[[nodiscard]]
	int 					read_size() const;

private :

	bool					is_ready_to_use{false};
	int 					size{0};
};


