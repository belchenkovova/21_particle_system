#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"

class				gui::icon : public gui::object
{
public :

	explicit		icon(const string &source);
					~icon() override = default;

	void			render() const override;

private :

	engine::texture	texture;
};


