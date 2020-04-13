#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"

class				gui::icon : public gui::object
{
public :

	explicit		icon(const string &source);
					~icon() override = default;
private :

	void			render_virtual() const override;

	engine::texture	texture;
};


