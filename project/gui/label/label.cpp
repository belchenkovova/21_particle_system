#include "label.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

					label::label(
					const string &text,
					const shared_ptr<class font> &font) :
					text(text),
					font(font)
{
	is_latent = true;
	required_size = point();

	for (const char &iter : text)
	{
		auto		&symbol = font->find_symbol(iter);

		required_size->x += symbol.read_advance();
		required_size->y = std::max(required_size->y, symbol.read_size().y);
	}
}

void				label::render_virtual() const
{
	assert(gui::renderers);

	point			position_iterator;
	point			position_current;

	position_iterator.x = position->x + (current_size->x - required_size->x) / 2;
	position_iterator.y = position->y + (current_size->y - required_size->y) / 2;
	position_iterator.y += required_size->y;


	for (const auto &text_iterator : text)
	{
		auto		symbol = font->find_symbol(text_iterator);

		position_current.x = position_iterator.x + symbol.read_bearing().x;
		position_current.y = position_iterator.y - symbol.read_bearing().y;

		renderers->text.render(position_current, symbol.read_size(), font->color, symbol.read_texture());

		position_iterator.x += symbol.read_advance();
	}
}
