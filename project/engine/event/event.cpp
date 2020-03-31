#include "event.h"

using namespace				engine;

event::type					event::read_type() const
{
	return (type_value);
}

optional<int>				event::read_key() const
{
	return (key);
}

optional<pair<int, int>>	event::read_mouse() const
{
	return (mouse);
}

void						event::reset()
{
	type_value = type::none;
	key = {};
	mouse = {};
}

void						event::reset_if_needed()
{
	if (type_value == type::key_hold)
		return ;
	if (type_value == type::mouse_hold)
		return ;
	reset();
}