#pragma once

#include "particle_system/namespace.h"

#include "particle_system/object/object.h"

class				particle_system::map : private vector<object>
{
public :

	explicit 		map(const string &source);
					~map() = default;

	using			vector<object>::at;
	using			vector<object>::size;
};


