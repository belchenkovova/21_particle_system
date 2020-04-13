#pragma once

#include "gui/namespace.h"
#include "gui/abstract/property.h"

class				gui::owner
{
public :

	explicit		owner(const shared_ptr<object> &target) : property(target) {}
	virtual			~owner() = default;

protected :

	property		property;
};
