#include "label.h"

using namespace		gui;

					label::label(
					const point &center,
					const class font &font,
					const string &text) :
					center(center),
					font(font)
{
	replace_text(text);
}

void				label::replace_text(const string &new_text)
{
	text = new_text;
	size = point();

	for (const char &iter : text)
	{
		auto		&symbol = font.find_symbol(iter);

		size.x += symbol.read_advance();
		size.y = std::max(size.y, symbol.read_size().y);
	}
}

void				label::start_renderer(const engine::core &core)
{
	renderer.emplace(core);
}

void				label::render()
{
	point			position_iterator;
	point			position_this;
	point			size_this;

	position_iterator.x = center.x - size.x / 2;
	position_iterator.y = center.y + size.y / 2;

	renderer->program.upload_uniform("uniform_color", font.color);

	for (const auto &text_iterator : text)
	{
		auto		symbol = font.find_symbol(text_iterator);

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
