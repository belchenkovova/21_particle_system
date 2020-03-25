#include "common.h"

std::string				common::read_file(const std::string &source)
{
	std::ifstream		file;
	std::stringstream	stream;

	file.open(source);
	if (not file.is_open())
		throw (exception("Tools : File reading error"));

	stream << file.rdbuf();
	file.close();
	return (stream.str());
}