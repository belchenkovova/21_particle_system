#pragma once

#include "engine/namespace.h"

class							engine::event final
{
	friend class				core;

public :

	enum class					type
	{
		none,
		key_press,
		key_release,
		key_hold,
		mouse_move,
		mouse_press,
		mouse_release,
		mouse_hold,
		rendering
	};

								event() = default;
								~event() = default;

	[[nodiscard]]
	type						read_type() const;
	[[nodiscard]]
	optional<int>				read_key() const;
	[[nodiscard]]
	optional<pair<int, int>>	read_mouse() const;

private :

	type						type_value{type::none};

	optional<int>				key;
	optional<pair<int, int>>	mouse;

	void						reset();
	void						reset_if_needed();
};


