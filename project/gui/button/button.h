#pragma once

#include "gui/namespace.h"
#include "gui/abstract/editor.h"
#include "gui/abstract/object.h"

class								gui::button : public gui::editor, public gui::object
{
	friend class					gui::system;
	friend class					gui::button_pack;

public :

	static inline glm::vec3			body_color{0.f, 0.f, 0.f};
	static inline glm::vec3			frame_color{0.f, 0.f, 0.f};
	static inline glm::vec4			active_mask{0.f, 0.f, 0.f, 0.f};
	static inline int				frame_width{0};

	explicit						button(const functor &functor, bool is_toggle = true);
									~button() override = default;

	void							render() const override;

private :

	bool							is_toggle = false;
	bool							is_pressed = false;

	void							functor_press();
	void							functor_release();
};


