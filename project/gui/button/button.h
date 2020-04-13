#pragma once

#include "gui/namespace.h"
#include "gui/abstract/owner.h"
#include "gui/rectangle/rectangle.h"

class				gui::button : public gui::rectangle, public gui::owner
{
	friend class	gui::system;
	friend class	gui::button_pack;

public :

	point			indent;
	glm::vec4		active_color = glm::vec4(0.f, 0.f, 0.f, 0.f);

					button(
					const functor &functor,
					const shared_ptr<object> &content,
					bool is_toggle = true);
					~button() override = default;
private :

	void			reload_virtual() override;
	void			render_virtual() const override;

	bool			is_toggle = false;
	bool			is_pressed = false;

	void			functor_press();
	void			functor_release();
};


