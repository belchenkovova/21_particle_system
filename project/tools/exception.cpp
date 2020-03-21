#include "tools/tools.h"

					tools::exception::exception(const char *message) :
					std::exception(), message(message)
{}

const char			*tools::exception::what() const noexcept
{
	return (message);
}