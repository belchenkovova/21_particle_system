#pragma once

#include "gui/namespace.h"
#include "gui/abstract/editor.h"
#include "gui/abstract/object.h"

class								gui::button : public gui::editor, public gui::object
{
	friend class					gui::system;
	friend class					gui::button_pack;

public :

	static inline glm::vec3			body_color{0.f, 0.f, 0.f};
	static inline glm::vec3			frame_color{0.f, 0.f, 0.f};
	static inline int				frame_width{0};

	explicit						button(const functor &functor, bool is_toggle = true);
									~button() override = default;

	void							render() const override;

private :

	bool							is_toggle = false;
	bool							is_pressed = false;

	void							functor_press();
	void							functor_release();

	static void 					start(const engine::core &core);

	static inline struct			renderers
	{
		using						points_type = engine::vbo::real<float, 2>;
		using						points_ptr_type = shared_ptr<points_type>;

		class						first final : public engine::renderer
		{
		public :
									explicit first(const engine::core &core);
									~first() override = default;

			void					render() const override;

			points_ptr_type			points;

			using					engine::renderer::program;
		};

		class						second final : public engine::renderer
		{
		public :
			explicit				second(const engine::core &core);
									~second() override = default;

			void					render() const override;

			points_ptr_type			points;
			using					engine::renderer::program;
		};

		unique_ptr<first>			first;
		unique_ptr<second>			second;
	}								renderers;
};


