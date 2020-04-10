#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"
#include "gui/font/font.h"

class							gui::label : public gui::object
{
	friend class				gui::system;

public :
								label(
								const string &text,
								const shared_ptr<font> &font);
								~label() override = default;

	void						render() const override;

private :

	string						text;
	const shared_ptr<font>		font;
};