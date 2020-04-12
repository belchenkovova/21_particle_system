#pragma once

#include "engine/namespace.h"
#include "engine/vbo/vbo.h"
#include "engine/vao/vao.h"
#include "engine/ebo/ebo.h"

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

	void					use_indexing(int size);
	ebo						&receive_indices();

private :

	bool					is_ready_to_use = false;
	int 					size = 0;

	bool					uses_indexing = false;
	shared_ptr<ebo>			ebo = nullptr;
};


