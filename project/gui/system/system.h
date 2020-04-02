#pragma once

#include "gui/namespace.h"
#include "gui/font/font.h"
#include "gui/label/label.h"

class						gui::system final
{
public :

	explicit				system(engine::core &engine);
							~system() = default;

private :

	engine::core			&core;

	void					callback();

	font					font;
	label					label;

};
