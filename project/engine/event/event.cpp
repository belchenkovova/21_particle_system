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

vec2					event::read_mouse_position() const
{
	revise_optional(mouse_position);
	return (*mouse_position);
}

vec2					event::read_mouse_scroll() const
{
	revise_optional(mouse_scroll);
	return (*mouse_scroll);
}

void					event::reset()
{
	type_value = type::none;
	key_value = {};
	mouse_position = {};
	mouse_scroll = {};
}

void					event::reset_if_needed()
{
	if (type_value == type::key_hold)
		return ;
	if (type_value >= type::mouse_hold)
		return ;
	reset();
}