#pragma once

#include "gui/namespace.h"

class					gui::object
{
	friend class 		gui::system;
	friend class 		gui::editor;

public :

#pragma message "Debug version only"
	static inline int	id_counter = 0;
	int					id = id_counter++;

#pragma message "Debug version only"
	void 				info() const
	{
#define M1(o)			(o.has_value() ? *o : point(-1))

		std::cout << "Object : id = " << id << std::endl;
		std::cout << "required size = " << M1(required_size) << std::endl;
		std::cout << "current size = " << M1(current_size) << std::endl;
		std::cout << "position = " << M1(position) << std::endl;
	}

						object() = default;
	virtual				~object() = default;

protected :

	virtual void		render() const {}

	virtual void		reload() {}

	bool 				is_latent = false;

	optional<point>		required_size;
	optional<point>		current_size;

	optional<point>		position;

	using 				functor_type = list<functor>;
	struct
	{
		functor_type	press;
		functor_type	release;
	}					functors;

	void 				revise_self() const
	{
		gui::revise_optional(required_size);
		gui::revise_optional(current_size);
		gui::revise_optional(position);

		if (current_size < required_size)
			throw (common::exception("GUI, Space : Bad current size"));
	}

public :

	[[nodiscard]]
	point				read_required_size() const
	{
		gui::revise_optional(required_size);
		return (*required_size);
	}

	[[nodiscard]]
	point				read_current_size() const
	{
		gui::revise_optional(current_size);
		return (*current_size);
	}

	[[nodiscard]]
	point				read_position() const
	{
		gui::revise_optional(position);
		return (*position);
	}

	[[nodiscard]]
	bool				have_position() const
	{
		return (position.has_value());
	}

private :

	[[nodiscard]]
	bool				test_point(const point &point) const
	{
		if (position.has_value() and current_size.has_value())
			return (point > *position and point < *position + *current_size);
		return false;
	}

	void				invoke_press_functors() const
	{
		for (const auto &functor : functors.press)
			functor.run();
	}

	void				invoke_release_functors() const
	{
		for (const auto &functor : functors.release)
			functor.run();
	}
};


