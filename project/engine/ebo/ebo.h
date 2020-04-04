#pragma once

#include "engine/namespace.h"

class							engine::ebo : private object_wrapper<GLuint>, private vector<unsigned int>
{
	friend class 				engine::buffer;

public :

								ebo();
								~ebo() override;

	virtual void				bind(bool state) const;

	using						vector<unsigned int>::at;

	void 						resize(int size);
	[[nodiscard]]
	GLuint						read_size() const;
	void						save();
};