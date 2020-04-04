#pragma once

#include "gui/namespace.h"
#include "gui/point/point.h"

class				gui::space
{
public :

					space() = default;
	virtual			~space() = default;

	virtual void	render() const = 0;

protected :

	point			min;
	point			max;
};


