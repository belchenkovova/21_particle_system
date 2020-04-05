#pragma once

#include "gui/namespace.h"
#include "gui/space/space.h"
#include "gui/font/font.h"

class							gui::label : public gui::space
{
	friend class				gui::system;

public :
								label(
								const point &center,
								const font &font,
								const string &text = "");
								~label() override = default;

	void						replace_text(const string &new_text);
	void						render() const override;

private :

	const point					center;
	const font					&font;
	string						text;

private :

	static void					start(const engine::core &core);

	class						renderer final : public engine::renderer::OpenGL
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

		using 					OpenGL::program;
	};

	using						renderer_type = unique_ptr<renderer>;
	static inline renderer_type	renderer;
};