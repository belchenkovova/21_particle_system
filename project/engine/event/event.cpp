#include "event.h"

using namespace			engine;

event::type				event::read_type() const
{
	return (type_value);
}

optional<event::key>	event::read_key() const
{
	return (key_value);
}

optional<point>			event::read_mouse() const
{
	return (mouse_value);
}

void					event::reset()
{
	type_value = type::none;
	key_value = {};
	mouse_value = {};
}

void					event::reset_if_needed()
{
	if (type_value == type::key_hold)
		return ;
	if (type_value == type::mouse_hold)
		return ;
	reset();
}