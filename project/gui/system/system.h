#pragma once

#include "gui/namespace.h"
#include "gui/font/font.h"
#include "gui/label/label.h"
#include "gui/icon/icon.h"
#include "gui/button/button.h"
#include "gui/pack/pack.h"
#include "gui/pack/button_pack.h"
#include "gui/drawer/drawer.h"

class						gui::system final
{
public :

#pragma message "Debug only"
	void					info()
	{
		std::cout << "GUI, System : " << std::endl;
		for (int i = 0; i < objects.size(); i++)
			std::cout << "[" << i << "] : id = " << objects[i]->id << std::endl;
		std::cout << std::endl;
	}

	explicit				system(engine::core &engine);
							~system() = default;

	template				<typename type, typename ...args_type>
	auto					generate(args_type &&...args)
	{
		if constexpr (is_same_v<type, font>);
		else if constexpr (is_same_v<type, label>);
		else if constexpr (is_same_v<type, icon>);
		else if constexpr (is_same_v<type, button>);
		else if constexpr (is_same_v<type, pack>);
		else if constexpr (is_same_v<type, button_pack>);
		else if constexpr (is_same_v<type, drawer>);
		else
			static_assert(not is_same_v<type, type>, "GUI, System : Should generate instance of given type");

		auto 				pointer = make_shared<type>(args...);

		if constexpr (is_same_v<type, font>)
			fonts.push_back(pointer);
		else if constexpr (is_same_v<type, drawer>)
		{
			pointer->transition_timer = &core.generate_timer(
				drawer::transition_period, &drawer::transition_function, pointer.get());
			pointer->transition_timer->block = true;
			objects.push_back(static_pointer_cast<object>(pointer->button));
			objects.push_back(static_pointer_cast<object>(pointer));
		}
		else
			objects.push_back(static_pointer_cast<object>(pointer));
		return (pointer);
	}

	engine::renderer		&receive_renderer();

private :

	engine::core			&core;

	using					fonts_type = vector<shared_ptr<font>>;
	fonts_type				fonts;

	using					objects_type = vector<shared_ptr<object>>;
	objects_type			objects;

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
