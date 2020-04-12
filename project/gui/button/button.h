#pragma once

#include "gui/namespace.h"
#include "gui/abstract/editor.h"
#include "gui/rectangle/rectangle.h"

class				gui::button : public gui::editor, public gui::rectangle
{
	friend class	gui::system;
	friend class	gui::button_pack;

public :

	glm::vec4		active_color = glm::vec4(0.f, 0.f, 0.f, 0.f);

	explicit		button(const functor &functor, bool is_toggle = true);
					~button() override = default;

	void			render() const override;

private :

	bool			is_toggle = false;
	bool			is_pressed = false;

	void			functor_press();
	void			functor_release();
};


