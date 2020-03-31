#include "font.h"

using namespace		gui;

					font::font(const std::string &source, int width)
{
	if (FT_Init_FreeType(&library))
		throw (common::exception("GUI, Font : Can't start FreeType library"));

	if (FT_New_Face(library, source.c_str(), 0, &face))
		throw (common::exception("GUI, Font : Can't parse font"));

	FT_Set_Pixel_Sizes(face, 0, width);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (int i = 0; i < size; i++)
		map.emplace(i, build_symbol(static_cast<char>(i)));
}

					font::~font()
{
	FT_Done_Face(face);
	FT_Done_FreeType(library);
}

const symbol		&font::find_symbol(char task) const
{
	auto			result = map.find(task);

	if (result == map.end())
		throw (common::exception("GUI, Font : Symbol not found"));
	return (result->second);
}



symbol				font::build_symbol(char task)
{
	if (FT_Load_Char(face, task, FT_LOAD_RENDER))
		throw (common::exception("GUI, Font : Can't build symbol"));

	//return (symbol(face));
}
