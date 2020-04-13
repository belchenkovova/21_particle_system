#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"

class				gui::rectangle : public gui::object
{
public :

					rectangle() = default;
					~rectangle() override = default;

	glm::vec3		body_color = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3		frame_color = glm::vec3(0.f, 0.f, 0.f);
	int				frame_width = 0;

protected :

	void			render_virtual() const override;
};


