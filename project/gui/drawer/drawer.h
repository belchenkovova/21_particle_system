#pragma once

#include "gui/namespace.h"
#include "gui/abstract/container.h"

class							gui::drawer final : public gui::container, public gui::object
{
	friend class				gui::system;

public :
								drawer(shared_ptr<object> &target, float relative_position = 0.5f);
								~drawer() override = default;

	void						show(bool state);

private :

	void						render_virtual() const override;

	const shared_ptr<object>	&target;
	const float					relative_position = 0;
};


