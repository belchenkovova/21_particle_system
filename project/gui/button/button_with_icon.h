#pragma once

#include "gui/namespace.h"
#include "gui/button/button.h"
#include "gui/icon/icon.h"

class				gui::button_with_icon : public gui::button
{
public :

	point			indent;

					button_with_icon(
					const class functor &functor,
					const string &source);
					~button_with_icon() override = default;

	void			render() const override;
	void			reload() override;

private :

	icon			icon;
};


