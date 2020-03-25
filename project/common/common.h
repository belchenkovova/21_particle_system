#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

namespace			common
{
	class			exception : public std::exception
	{
	public :

		explicit	exception(const char *message);
		[[nodiscard]]
		const char	*what() const noexcept override;

	private :

		const char	*message;
	};

	std::string		read_file(const std::string &source);
};