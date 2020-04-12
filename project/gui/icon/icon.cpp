#include "icon.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

					icon::icon(const string &source) :
					texture(source)
{
	is_latent = true;
	required_size = texture.read_size();
}

void				icon::render() const
{
	revise_self();
	renderers->texture.render(
		*position + (*current_size - *required_size) / 2,
		*required_size,
		texture);
}