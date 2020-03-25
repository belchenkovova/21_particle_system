#include "common.h"

					common::exception::exception(const char *message) :
					std::exception(), message(message)
{}

const char			*common::exception::what() const noexcept
{
	return (message);
}