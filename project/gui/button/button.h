#pragma once

#include "gui/namespace.h"
#include "gui/abstract/editor.h"
#include "gui/abstract/object.h"

class							gui::button : public gui::editor, public gui::object
{
	friend class				gui::system;

public :

	static inline glm::vec3		body_color{0.f, 0.f, 0.f};
	static inline glm::vec3		frame_color{0.f, 0.f, 0.f};
	static inline int			frame_width{0};

	explicit					button(const functor &functor);
								~button() override = default;

	void						render() const override;

protected :

	static void 				start(const engine::core &core);

	class						renderer final : public engine::renderer
	{
	public :
		explicit				renderer(const engine::core &core);
		~renderer()				override = default;

		void					render() const override;

		using					points_type = engine::vbo::real<float, 2>;
		using					points_ptr_type = shared_ptr<points_type>;

		points_ptr_type			points;

		using					engine::renderer::program;
	};

	using						renderer_type = unique_ptr<renderer>;
	static inline renderer_type	renderer;
};


