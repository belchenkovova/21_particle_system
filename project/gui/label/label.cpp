#include "label.h"

using namespace		gui;

					label::label(
					const string &text,
					const shared_ptr<class font> &font) :
					text(text),
					font(font)
{
	required_size = point();

	for (const char &iter : text)
	{
		auto		&symbol = font->find_symbol(iter);

		required_size->x += symbol.read_advance();
		required_size->y = std::max(required_size->y, symbol.read_size().y);
	}
}

void				label::render() const
{
	revise_self();
	assert(renderer);

	point			position_iterator;
	point			position_this;
	point			size_this;

	position_iterator.x = position->x + (current_size->x - required_size->x) / 2;
	position_iterator.y = position->y + (current_size->y - required_size->y) / 2;
	position_iterator.y += required_size->y;

	renderer->program->upload_uniform("uniform_color", font->color);

	for (const auto &text_iterator : text)
	{
		auto		symbol = font->find_symbol(text_iterator);

		position_this.x = position_iterator.x + symbol.read_bearing().x;
		position_this.y = position_iterator.y - symbol.read_bearing().y;

		size_this = symbol.read_size();

		float		data[] =
		{
			(float)position_this.x + (float)size_this.x, (float)position_this.y,
			(float)position_this.x, (float)position_this.y,
			(float)position_this.x, (float)position_this.y + (float)size_this.y,
			(float)position_this.x + (float)size_this.x, (float)position_this.y + (float)size_this.y
		};

		for (int i = 0; i < 8; i++)
			renderer->points->at(i) = data[i];
		renderer->points->save();

		symbol.read_texture().bind(true);
		renderer->render();
		symbol.read_texture().bind(false);

		position_iterator.x += symbol.read_advance();
	}
}
