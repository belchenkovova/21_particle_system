#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"
#include "gui/font/font.h"

class							gui::label : public gui::object
{
	friend class				gui::system;

public :
								label(
								const string &text,
								const shared_ptr<font> &font);
								~label() override = default;

	void						render() const override;

private :

	string						text;
	const shared_ptr<font>		font;

private :

	static void					start(const engine::core &core);

	class						renderer final : public engine::renderer
	{
	public :
		explicit				renderer(const engine::core &core);
								~renderer() override = default;

		void					render() const override;

		using					points_type = engine::vbo::real<float, 2>;
		using					texture_type = engine::vbo::real<float, 2>;
		using					points_ptr_type = shared_ptr<points_type>;
		using					texture_ptr_type = shared_ptr<texture_type>;

		points_ptr_type			points;
		texture_ptr_type		texture;

		using 					engine::renderer::program;
	};

	using						renderer_type = unique_ptr<renderer>;
	static inline renderer_type	renderer;
};