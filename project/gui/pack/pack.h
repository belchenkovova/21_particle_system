#pragma once

#include "gui/namespace.h"
#include "gui/abstract/container.h"
#include "gui/rectangle/rectangle.h"

class					gui::pack : public gui::rectangle, public gui::container
{
public :

	int					spacing = 0;
	point				indent;

						pack(orientation orientation, bool align_size);
						pack(orientation orientation, bool align_size, const point &position);
						~pack() override = default;

	property			&add_item(const shared_ptr<object> &item) override;

private :

	const orientation	orientation;
	const bool			align_size;

	void 				reload_virtual() override;
	void				render_virtual() const override;
};