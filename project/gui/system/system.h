#pragma once

#include "gui/namespace.h"
#include "gui/font/font.h"
#include "gui/label/label.h"

class							gui::system final
{
public :

	explicit						system(engine::core &engine);
									~system() = default;

	template						<typename ...t_args>
	shared_ptr<label>				generate_label(t_args &&...args)
	{
		auto						label = make_shared<class label>(args...);
		auto						space = static_pointer_cast<class space>(label);

		spaces.push_back(space);
		return (label);
	}

	const engine::renderer::pure	&receive_renderer();

private :

	engine::core					&core;

	using							spaces_type = vector<shared_ptr<space>>;
	spaces_type						spaces;

	class							renderer final : public engine::renderer::pure
	{
	public :

		explicit					renderer(const spaces_type &spaces);
									~renderer() override = default;

		void						render() const override;

		const spaces_type			&spaces;
	}								renderer;

	void							callback();
};
