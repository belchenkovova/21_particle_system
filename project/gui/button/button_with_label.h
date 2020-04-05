#pragma once

#include "gui/namespace.h"
#include "gui/button/button.h"
#include "gui/label/label.h"

class				gui::button_with_label : public gui::button
{
public :
					button_with_label(
					const class functor &functor,
					const point &center,
					const class font &font,
					const string &text = "");
					~button_with_label() override = default;

	void			render() const override;
	void			replace_text(const string &new_text);

private :

	label			label;

	void			reload_space();
};