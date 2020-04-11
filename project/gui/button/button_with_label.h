#pragma once

#include "gui/namespace.h"
#include "gui/button/button.h"
#include "gui/label/label.h"

class					gui::button_with_label final : public gui::button
{
public :

	point				indent;

						button_with_label(
						const class functor &functor,
						const string &text,
						const shared_ptr<font> &font);
						~button_with_label() override = default;

	void				render() const override;
	void				reload() override;

private :

	label				label;
};