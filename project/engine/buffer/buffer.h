#pragma once

#include "engine/namespace.h"
#include "engine/vbo/vbo.h"
#include "engine/vao/vao.h"

class						engine::buffer final : private engine::vao
{
	friend class 			engine::core;

public :
							buffer() = default;
							~buffer() override = default;

	using					engine::vao::generate_attribute;
	using					engine::vao::receive_attribute;
	using					engine::vao::receive_attribute_as_pointer;

	void					resize(int size);
	void					save();
	void					bind(bool state) const override;

private :

	bool					is_ready_to_use = false;
	int 					size = 0;
};


