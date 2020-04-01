#pragma once

#include "gui/namespace.h"

class						gui::system final
{
public :

	explicit				system(engine::core &engine);
							~system() = default;

private :

	engine::core			&engine;

private :

	class					text_renderer final : public engine::renderer
	{
	public :
		explicit			text_renderer(engine::core &engine);
							~text_renderer() override = default;

		void				render() override;

		using 				points_type = engine::vbo::real<float, 2>;
		using 				texture_type = engine::vbo::real<float, 2>;
		using 				points_ptr_type = std::shared_ptr<points_type>;
		using 				texture_ptr_type = std::shared_ptr<texture_type>;

	private :

		points_ptr_type		points;
		texture_ptr_type	texture;
	}						text_renderer;
};
