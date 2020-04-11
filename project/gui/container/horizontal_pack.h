#pragma once

#include "gui/namespace.h"
#include "gui/container/container.h"

class					gui::horizontal_pack : public gui::container
{
public :

	int					spacing = 0;
	point				indent;

						horizontal_pack() = default;
	explicit			horizontal_pack(const point &position);
						~horizontal_pack() override = default;

	void 				reload() override;
	void				render() const override;
};