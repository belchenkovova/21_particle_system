#pragma once

#include "gui/namespace.h"
#include "gui/abstract/owner.h"
#include "gui/rectangle/rectangle.h"

class				gui::button final : public gui::rectangle, private gui::owner
{
	friend class	gui::system;
	friend class	gui::button_pack;
	friend class	gui::drawer;

public :

	point			indent;
	glm::vec4		active_color = glm::vec4(0.f, 0.f, 0.f, 0.f);

	template		<typename ...args_type>
	explicit		button(const functor &functor, args_type ...args) :
					owner(args...)
	{
		button::reload_virtual();
		is_latent = true;
		functors.press.emplace_back(&gui::button::functor_press, this);
		if (not is_toggle)
			functors.release.emplace_back(&gui::button::functor_release, this);
		functors.press.push_back(functor);
	}
					~button() override = default;

	void			make_toggle();

private :

	void			reload_virtual() override;
	void			render_virtual() const override;

	bool			is_toggle = false;
	bool			is_pressed = false;

	void			functor_press();
	void			functor_release();
};


