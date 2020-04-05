#pragma once

#include "gui/namespace.h"
#include "gui/space/space.h"

class							gui::button : public gui::space
{
	friend class				gui::system;

public :

	explicit					button(const functor &functor);
								~button() override = default;

	void						render() const override;

protected :

	static void 				start(const engine::core &core);

	class						renderer final : public engine::renderer::OpenGL
	{
	public :
		explicit				renderer(const engine::core &core);
		~renderer()				override = default;

		void					render() const override;

		using					points_type = engine::vbo::real<float, 2>;
		using					points_ptr_type = shared_ptr<points_type>;

		points_ptr_type			points;
	};

	using						renderer_type = unique_ptr<renderer>;
	static inline renderer_type	renderer;
};


