#pragma once

#include "gui/namespace.h"
#include "gui/space/space.h"
#include "gui/font/font.h"
#include "gui/label/label.h"
#include "gui/button/button_with_label.h"

class								gui::system final
{
public :

	explicit						system(engine::core &engine);
									~system() = default;

	template						<typename ...t_args>
	void							generate_label(t_args &&...args)
	{
		auto						label = make_shared<class label>(args...);
		auto						space = static_pointer_cast<class space>(label);

		spaces.push_back(space);
	}

	template						<typename ...t_args>
	void							generate_button(t_args &&...args)
	{
		auto						button = make_shared<class button_with_label>(args...);
		auto						space = static_pointer_cast<class space>(button);

		spaces.push_back(space);
	}

	const engine::renderer::pure	&receive_renderer();

private :

	engine::core					&core;

	using							spaces_type = vector<shared_ptr<space>>;
	spaces_type						spaces;

	void							functor_press();
	void							functor_release();

private :

	class							renderer final : public engine::renderer::pure
	{
	public :

		explicit					renderer(const spaces_type &spaces);
									~renderer() override = default;

		void						render() const override;

		const spaces_type			&spaces;
	}								renderer;
};
