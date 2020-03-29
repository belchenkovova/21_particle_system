#include "callback.h"

using namespace			engine;

						callback::callback(std::function<void()> &function) :
						function(function)
{}

void 					callback::run() const
{
	function();
}