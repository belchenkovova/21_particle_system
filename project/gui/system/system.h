#pragma once

#include "gui/namespace.h"
#include "gui/font/font.h"
#include "gui/label/label.h"
#include "gui/button/button_with_label.h"
#include "gui/container/horizontal_pack.h"
#include "gui/container/button_pack.h"

class						gui::system final
{
public :

	explicit				system(engine::core &engine);
							~system() = default;

	template				<typename ...args_type>
	auto					generate_font(args_type &&...args)
	{
		auto 				pointer = make_shared<font>(args...);

		fonts.push_back(pointer);
		return (pointer);
	}

	template				<typename ...args_type>
	auto					generate_button_with_label(args_type &&...args)
	{
		auto 				pointer = make_shared<button_with_label>(args...);

		render_objects.push_back(static_pointer_cast<object>(pointer));
		return (pointer);
	}

	template				<typename ...args_type>
	auto					generate_horizontal_pack(args_type &&...args)
	{
		auto 				pointer = make_shared<horizontal_pack>(args...);

		non_render_objects.push_back(static_pointer_cast<object>(pointer));
		return (pointer);
	}

	template				<typename ...args_type>
	auto					generate_button_pack(args_type &&...args)
	{
		auto 				pointer = make_shared<button_pack>(args...);

		non_render_objects.push_back(static_pointer_cast<object>(pointer));
		return (pointer);
	}


	engine::renderer		&receive_renderer();

private :

	engine::core			&core;

	using					fonts_type = vector<shared_ptr<font>>;
	fonts_type				fonts;

	using					objects_type = vector<shared_ptr<object>>;
	objects_type			render_objects;
	objects_type			non_render_objects;

	void					functor_press();
	void					functor_release();

private :

	class					renderer final : public engine::renderer
	{
	public :

		explicit			renderer(const objects_type &objects);
							~renderer() override = default;

		void				render() override;

		const objects_type	&objects;
	}						renderer;
};
