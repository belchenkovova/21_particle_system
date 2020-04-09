#pragma once

#include "gui/namespace.h"
#include "gui/button/button.h"
#include "gui/label/label.h"

class					gui::button_with_label : public gui::button
{
public :

	static inline point	indent{};

public :
						button_with_label(
						const class functor &functor,
						const string &text,
						const shared_ptr<font> &font);
						~button_with_label() override = default;

	void				render() const override;
	void				reload() override;

private :

	label				label;
	point				final_indent;
};