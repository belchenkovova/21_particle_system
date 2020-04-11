#pragma once

#include "gui/namespace.h"
#include "gui/container/container.h"

class					gui::vertical_pack : public gui::container
{
public :

	int					spacing = 0;
	point				indent;

						vertical_pack();
	explicit			vertical_pack(const point &position);
						~vertical_pack() override = default;

	void 				reload() override;
	void				render() const override;
};


