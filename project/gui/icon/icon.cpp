#include "icon.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

					icon::icon(const string &source) :
					texture(source)
{
	is_latent = true;
	required_size = texture.read_size();
}

void				icon::render_virtual() const
{
	renderers->texture.render(
		*position + (*current_size - *required_size) / 2,
		*required_size,
		texture);
}