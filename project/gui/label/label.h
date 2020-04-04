#pragma once

#include "gui/namespace.h"
#include "gui/point/point.h"
#include "gui/font/font.h"

class						gui::label
{
	friend class 			gui::system;

public :
							~label() = default;

	void					replace_text(const string &new_text);
	void					render();

private :

							label(
							const point &center,
							const font &font,
							const string &text = "");

private :

	const point				center;
	const font				&font;
	string					text;
	point					size;

	class					renderer final : public engine::renderer
	{
	public :
		explicit			renderer(const engine::core &core);
		~renderer() override = default;

		void				render() override;

		using				points_type = engine::vbo::real<float, 2>;
		using				texture_type = engine::vbo::real<float, 2>;
		using				points_ptr_type = shared_ptr<points_type>;
		using				texture_ptr_type = shared_ptr<texture_type>;

		points_ptr_type		points;
		texture_ptr_type	texture;

		using 				engine::renderer::program;
	};

	using					renderer_ =  optional<renderer>;
	static inline renderer_ renderer;

	static void				start_renderer(const engine::core &core);
};


