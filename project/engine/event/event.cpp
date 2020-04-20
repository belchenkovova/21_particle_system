#include "event.h"

using namespace			engine;

event::type				event::read_type() const
{
	return (type_value);
}

enum key				event::read_key() const
{
	revise_optional(key_value);
	return (*key_value);
}

ivec2					event::read_mouse() const
{
	revise_optional(mouse_value);
	return (*mouse_value);
}

void					event::reset()
{
	type_value = type::none;
	key_value = {};
}

void					event::reset_if_needed()
{
	if (type_value == type::key_hold)
		return ;
	if (type_value >= type::mouse_hold)
		return ;
	reset();
}