#pragma once

#include "gui/namespace.h"

class					gui::renderers
{
public :

	explicit			renderers(const engine::core &core);
						~renderers() = default;

	using				vertex_type = engine::vbo::real<float, 2>;
	using				vertex_ptr_type = shared_ptr<vertex_type>;
	using				UV_type = engine::vbo::real<float, 2>;
	using				UV_ptr_type = shared_ptr<UV_type>;

private :

	const glm::mat4		projection;

public :

	class				text final : public engine::renderer
	{
	public :
		explicit		text(const glm::mat4 &projection);
						~text()	override = default;

		void			render() override;
		void 			render(
						const point &position,
						const point &size,
						const glm::vec3 &color,
						const engine::texture &target);
	private :

		vertex_ptr_type	vertex;
		UV_ptr_type		UV;
	}					text;

	class				rectangle final : public engine::renderer
	{
	public :
						explicit rectangle(const glm::mat4 &projection);
						~rectangle() override = default;

		void			render() override;
		void 			render(
						const point &position,
						const point &size,
						const glm::vec3 &color);
		void 			render(
						const point &position,
						const point &size,
						const glm::vec4 &color);
	private :

		vertex_ptr_type	vertex;
		using			renderer::program;
	}					rectangle;
};