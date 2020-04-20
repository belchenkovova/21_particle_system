#pragma once

#include "engine/namespace.h"

class				engine::event final
{
	friend class	core;

public :

	enum class		type
	{
		none,
		key_press,
		key_release,
		key_hold,
		mouse_move,
		mouse_press,
		mouse_release,
		mouse_hold
	};

					event() = default;
					~event() = default;

	[[nodiscard]]
	type			read_type() const;
	[[nodiscard]]
	enum key		read_key() const;
	[[nodiscard]]
	ivec2			read_mouse() const;

private :

	type			type_value{type::none};

	optional<key>	key_value;
	optional<ivec2>	mouse_value;

	void			reset();
	void			reset_if_needed();
};


